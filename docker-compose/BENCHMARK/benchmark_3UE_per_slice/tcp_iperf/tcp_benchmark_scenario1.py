#!/usr/bin/env python3

import subprocess
import re
import csv
import os

def run_command_in_container(container, command):
    result = subprocess.run(['docker', 'exec', container] + command, capture_output=True, text=True)
    return result.stdout

def install_packages(container):
    print(f"Installing packages in {container}...")
    run_command_in_container(container, ['apt-get', 'update'])
    run_command_in_container(container, ['apt-get', 'install', '-y', 'iputils-ping', 'iperf3'])

def parse_iperf_tcp(output):
    interval_bitrate = []
    # Improved regex pattern to extract interval and bitrate
    pattern = re.compile(r'\[\s*\d+\]\s+(\d+\.\d+-\d+\.\d+)\s+sec\s+\d+\.\d+\s+\w+Bytes\s+(\d+\.\d+)\s+Mbits/sec')
    
    for match in pattern.finditer(output):
        interval, bitrate = match.groups()
        interval_bitrate.append({
            'interval': interval,
            'bitrate': float(bitrate)
        })
    
    return interval_bitrate

def benchmark_iperf_tcp(ue_container, dn_container, dn_ip, bind_address, duration):
    # Start iperf3 server in DN container
    print("Starting iperf3 server in DN container...")
    run_command_in_container(dn_container, ['iperf3', '-s', '-D'])
    
    # Run iperf3 client in UE container, specifying the bind address and duration
    print(f"Running iperf3 client in UE container for duration {duration} seconds...")
    iperf_output = run_command_in_container(ue_container, ['iperf3', '-c', dn_ip, '-B', bind_address, '-t', str(duration)])
    print("iPerf3 output:\n", iperf_output)  # Debugging output to check iperf3 output
    iperf_metrics = parse_iperf_tcp(iperf_output)
    print("Parsed metrics:", iperf_metrics)  # Debugging output to check parsed metrics
    
    # Kill iperf3 server in DN container
    print("Stopping iperf3 server in DN container...")
    run_command_in_container(dn_container, ['pkill', 'iperf3'])
    
    # Add duration to each interval's metrics
    for metric in iperf_metrics:
        metric['duration'] = duration
    
    return iperf_metrics

def write_csv(filename, fieldnames, data_list):
    file_exists = os.path.isfile(filename)
    with open(filename, mode='a', newline='') as file:
        writer = csv.DictWriter(file, fieldnames=fieldnames)
        if not file_exists:
            writer.writeheader()
        writer.writerows(data_list)

# Example usage:
ue_container = 'rfsim5g-oai-nr-ue1'  # UE container name
dn_container = 'oai-ext-dn'          # DN container name
dn_ip = '192.168.70.145'             # IP address of the DN container
bind_address = '12.1.1.130'          # Bind address for the interface
durations = [20]                     # List of durations for the iperf3 test

# Install necessary packages in both containers
install_packages(ue_container)
install_packages(dn_container)

# Perform the TCP benchmark for each duration
all_metrics = []
for duration in durations:
    metrics = benchmark_iperf_tcp(ue_container, dn_container, dn_ip, bind_address, duration)
    all_metrics.extend(metrics)

# Define the CSV filename
iperf_tcp_csv_file = 'iperf_tcp_metrics.csv'

# Write the results to CSV file
iperf_tcp_fieldnames = ['interval', 'bitrate', 'duration']
write_csv(iperf_tcp_csv_file, iperf_tcp_fieldnames, all_metrics)

print("iPerf TCP metrics for each duration:", all_metrics)

