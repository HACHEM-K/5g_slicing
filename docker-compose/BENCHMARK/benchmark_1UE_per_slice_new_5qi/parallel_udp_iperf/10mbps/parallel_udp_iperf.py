#!/usr/bin/env python3

import subprocess
import re
import csv
import os
import time
import datetime
import pandas as pd
from concurrent.futures import ThreadPoolExecutor

def run_command_in_container(container, command):
    result = subprocess.run(['docker', 'exec', container] + command, capture_output=True, text=True)
    return result.stdout

def install_packages(container):
    print(f"Installing packages in {container}...")
    run_command_in_container(container, ['apt-get', 'update'])
    run_command_in_container(container, ['apt-get', 'install', '-y', 'iputils-ping', 'iperf3'])

def parse_iperf_udp(output):
    interval_bitrate = []
    pattern = re.compile(r'\[\s*\d+\]\s+(\d+\.\d+-\d+\.\d+)\s+sec\s+\d+\.\d+\s+\w+Bytes\s+(\d+\.\d+)\s+Mbits/sec\s+\d+\s+(\d+\.\d+)%')
    matches = pattern.findall(output)
    # Exclude the last two interval measurements (sender and receiver summaries)
    if len(matches) > 2:
        matches = matches[:-2]
    for match in matches:
        interval, bitrate, loss = match
        interval_bitrate.append({
            'interval': interval,
            'bitrate': float(bitrate),
            'loss': float(loss)
        })
    return interval_bitrate

def start_iperf_server(dn_container, port):
    print(f"Starting iperf3 server on port {port} in DN container...")
    run_command_in_container(dn_container, ['iperf3', '-s', '-D', '-p', str(port), '-u'])

def stop_iperf_server(dn_container, port):
    print(f"Stopping iperf3 server on port {port} in DN container...")
    run_command_in_container(dn_container, ['pkill', '-f', f'iperf3 -s -D -p {port}'])

def benchmark_iperf_udp(ue_container, dn_ip, bind_address, duration, port, start_time, bandwidth):
    # Calculate sleep time to ensure synchronization
    current_time = datetime.datetime.now()
    sleep_time = (start_time - current_time).total_seconds()
    if sleep_time > 0:
        time.sleep(sleep_time)
    
    # Run iperf3 client in UE container, specifying the bind address, port, duration, interval, and bandwidth
    print(f"Running iperf3 client on port {port} in UE container for duration {duration} seconds with bandwidth {bandwidth}...")
    iperf_output = run_command_in_container(ue_container, ['iperf3', '-c', dn_ip, '-B', bind_address, '-p', str(port), '-u', '-t', str(duration), '-i', '1', '-b', bandwidth])
    print(f"iPerf3 output on port {port}:\n", iperf_output)
    iperf_metrics = parse_iperf_udp(iperf_output)
    print(f"Parsed metrics on port {port}:", iperf_metrics)
    for metric in iperf_metrics:
        metric['duration'] = duration
        metric['port'] = port
    return iperf_metrics

def write_csv(filename, fieldnames, data_list):
    data_df = pd.DataFrame(data_list)
    data_df[['interval_start', 'interval_end']] = data_df['interval'].str.split('-', expand=True).astype(float)
    sorted_df = data_df.sort_values(by=['port', 'interval_start'])
    sorted_df.drop(columns=['interval_start', 'interval_end'], inplace=True)
    sorted_df.to_csv(filename, index=False, columns=fieldnames)

# Configuration
ue_container = 'rfsim5g-oai-nr-ue1'  
dn_container = 'oai-ext-dn'          
dn_ip = '192.168.70.145'             
bind_address = '12.1.1.130'          
duration = 20                        
ports = [5201, 5202, 5203, 5204]     
bandwidth = '10M'  # Set the bandwidth limit to 10 Mbps

# Install necessary packages
install_packages(ue_container)
install_packages(dn_container)

# Start iperf3 servers
for port in ports:
    start_iperf_server(dn_container, port)
time.sleep(5)

# Define a start time in the near future
start_time = datetime.datetime.now() + datetime.timedelta(seconds=10)

# Benchmark in parallel
all_metrics = []
with ThreadPoolExecutor(max_workers=len(ports)) as executor:
    futures = [executor.submit(benchmark_iperf_udp, ue_container, dn_ip, bind_address, duration, port, start_time, bandwidth) for port in ports]
    for future in futures:
        all_metrics.extend(future.result())

# Stop iperf3 servers
for port in ports:
    stop_iperf_server(dn_container, port)

# Write results to CSV
iperf_udp_csv_file = 'parallel_iperf_udp_metrics.csv'
iperf_udp_fieldnames = ['interval', 'bitrate', 'loss', 'duration', 'port']
write_csv(iperf_udp_csv_file, iperf_udp_fieldnames, all_metrics)

print("iPerf UDP metrics for each duration:", all_metrics)

