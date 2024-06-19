#!/usr/bin/env python3

import subprocess
import re
import csv
import os
from multiprocessing import Process, Manager

def run_command_in_container(container, command):
    result = subprocess.run(['docker', 'exec', container] + command, capture_output=True, text=True)
    return result.stdout

def install_packages(container):
    print(f"Installing packages in {container}...")
    run_command_in_container(container, ['apt-get', 'update'])
    run_command_in_container(container, ['apt-get', 'install', '-y', 'iputils-ping', 'iperf'])

def parse_iperf_tcp(output):
    interval_bitrate = []
    # Improved regex pattern to extract interval and bitrate
    pattern = re.compile(r'\[\s*\d+\]\s+(\d+\.\d+-\d+\.\d+)\s+sec\s+\S+\s+\S+\s+(\d+\.\d+)\s+Mbits/sec')

    matches = pattern.findall(output)
    # Exclude the last two interval measurements (sender and receiver summaries)
    if len(matches) > 2:
        matches = matches[:-2]

    for match in matches:
        interval, bitrate = match
        interval_bitrate.append({
            'interval': interval,
            'bitrate': float(bitrate)
        })
    
    return interval_bitrate

def benchmark_iperf_tcp(ue_container, dn_container, dn_ip, bind_address, duration, interval, results):
    # Start iperf server in DN container
    print("Starting iperf server in DN container...")
    run_command_in_container(dn_container, ['iperf', '-s', '-D'])
    
    # Run iperf client in UE container, specifying the bind address, duration, and interval
    print(f"Running iperf client in UE container {ue_container} for duration {duration} seconds with interval {interval} seconds...")
    iperf_output = run_command_in_container(ue_container, ['iperf', '-c', dn_ip, '-B', bind_address, '-t', str(duration), '-i', str(interval)])
    print("iPerf output:\n", iperf_output)  # Debugging output to check iperf output
    iperf_metrics = parse_iperf_tcp(iperf_output)
    print("Parsed metrics:", iperf_metrics)  # Debugging output to check parsed metrics
    
    # Kill iperf server in DN container
    print("Stopping iperf server in DN container...")
    run_command_in_container(dn_container, ['pkill', 'iperf'])
    
    # Annotate each metric with the UE container name and duration
    for metric in iperf_metrics:
        metric['ue_container'] = ue_container
        metric['duration'] = duration
    
    results.extend(iperf_metrics)

def write_csv(filename, fieldnames, data_list):
    file_exists = os.path.isfile(filename)
    with open(filename, mode='a', newline='') as file:
        writer = csv.DictWriter(file, fieldnames=fieldnames)
        if not file_exists:
            writer.writeheader()
        writer.writerows(data_list)

# Example usage:
ue_containers = {
    'rfsim5g-oai-nr-ue1': '12.1.1.134',   # Existing UE container and bind address
    'rfsim5g-oai-nr-ue11': '12.1.1.135'   # New UE container and bind address
}
dn_container = 'oai-ext-dn'               # DN container name
dn_ip = '192.168.70.145'                  # IP address of the DN container
durations = [20]                          # List of durations for the iperf test
interval = 1                              # Interval for reporting bandwidth

# Install necessary packages in all UE containers and DN container
for ue_container in ue_containers.keys():
    install_packages(ue_container)
install_packages(dn_container)

# Perform the TCP benchmark for each duration on all UE containers simultaneously
with Manager() as manager:
    all_metrics = manager.list()

    processes = []
    for ue_container, bind_address in ue_containers.items():
        p = Process(target=benchmark_iperf_tcp, args=(ue_container, dn_container, dn_ip, bind_address, durations[0], interval, all_metrics))
        processes.append(p)
        p.start()

    # Wait for all processes to complete
    for p in processes:
        p.join()

    # Convert the manager list to a regular list for writing to CSV
    all_metrics = list(all_metrics)

    # Define the CSV filename
    iperf_tcp_csv_file = 'iperf_tcp_metrics.csv'

    # Write the results to CSV file
    iperf_tcp_fieldnames = ['interval', 'bitrate', 'duration', 'ue_container']
    write_csv(iperf_tcp_csv_file, iperf_tcp_fieldnames, all_metrics)

    print("iPerf TCP metrics for each duration:", all_metrics)

