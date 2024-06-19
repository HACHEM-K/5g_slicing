#!/usr/bin/env python3

import subprocess
import csv
import os
import json
import pandas as pd
import matplotlib.pyplot as plt

def run_command_in_container(container, command):
    result = subprocess.run(['docker', 'exec', container] + command, capture_output=True, text=True)
    return result.stdout

def install_packages(container):
    print(f"Installing packages in {container}...")
    run_command_in_container(container, ['apt-get', 'update'])
    run_command_in_container(container, ['apt-get', 'install', '-y', 'iputils-ping', 'iperf3', 'jq'])

def parse_iperf_udp(output):
    metrics = []
    try:
        result = json.loads(output)
        intervals = result['intervals']
        for interval in intervals:
            if 'sum' in interval:
                sum_metrics = interval['sum']
                # Ensure that we only add valid positive bandwidth values
                bandwidth = sum_metrics['bits_per_second'] / 1e6
                metrics.append({
                    'interval': f"{sum_metrics['start']}-{sum_metrics['end']}",
                    'bandwidth': bandwidth,  # Convert to Mbps
                    'jitter': result['end']['sum']['jitter_ms'],
                    'packet_loss': result['end']['sum']['lost_percent']
                })
    except json.JSONDecodeError as e:
        print(f"Error decoding JSON: {e}")
    except KeyError as e:
        print(f"Key error: {e}")
    return metrics

def benchmark_iperf_udp(ue_container, dn_container, dn_ip, bind_address, duration, bandwidth, num_tests):
    # Start iperf3 server in DN container
    print("Starting iperf3 server in DN container...")
    run_command_in_container(dn_container, ['iperf3', '-s', '-D'])
    
    all_metrics = []
    for i in range(num_tests):
        print(f"Running iperf3 UDP test {i+1}/{num_tests} in UE container for duration {duration} seconds with bandwidth {bandwidth}...")
        iperf_output = run_command_in_container(ue_container, ['iperf3', '-c', dn_ip, '-u', '-b', bandwidth, '-t', str(duration), '-J'])
        print("iPerf3 output:\n", iperf_output)  # Debugging output to check iperf3 output
        metrics = parse_iperf_udp(iperf_output)
        for metric in metrics:
            metric['test_num'] = i + 1
        print("Parsed metrics:", metrics)  # Debugging output to check parsed metrics
        all_metrics.extend(metrics)
    
    # Kill iperf3 server in DN container
    print("Stopping iperf3 server in DN container...")
    run_command_in_container(dn_container, ['pkill', 'iperf3'])
    
    return all_metrics

def write_csv(filename, fieldnames, data_list):
    file_exists = os.path.isfile(filename)
    with open(filename, mode='w', newline='') as file:
        writer = csv.DictWriter(file, fieldnames=fieldnames)
        if not file_exists:
            writer.writeheader()
        writer.writerows(data_list)

def plot_metrics(data):
    df = pd.DataFrame(data)
    
    fig, axes = plt.subplots(1, 2, figsize=(12, 6))
    
    # Box plot for Jitter
    df.boxplot(column='jitter', by='test_num', ax=axes[0])
    axes[0].set_title('Jitter per Test')
    axes[0].set_xlabel('Test Number')
    axes[0].set_ylabel('Jitter (ms)')
    for i in range(len(df)):
        axes[0].text(df['test_num'][i], df['jitter'][i], f"{df['jitter'][i]:.2f}", 
                     ha='center', va='bottom')

    # Box plot for Packet Loss
    df.boxplot(column='packet_loss', by='test_num', ax=axes[1])
    axes[1].set_title('Packet Loss per Test')
    axes[1].set_xlabel('Test Number')
    axes[1].set_ylabel('Packet Loss (%)')
    for i in range(len(df)):
        axes[1].text(df['test_num'][i], df['packet_loss'][i], f"{df['packet_loss'][i]:.2f}", 
                     ha='center', va='bottom')
    
    plt.suptitle('UDP metrics per test for bandwidth of 20Mbps')
    plt.tight_layout(rect=[0, 0.03, 1, 0.95])
    plt.show()

# Example usage:
ue_container = 'rfsim5g-oai-nr-ue1'  # UE container name
dn_container = 'oai-ext-dn'          # DN container name
dn_ip = '192.168.70.145'             # IP address of the DN container
bind_address = '12.1.1.130'          # Bind address for the interface
duration = 20                        # Duration for the iperf3 test
bandwidth = '20M'                    # Bandwidth limit for the UDP test
num_tests = 5                        # Number of tests to run

# Install necessary packages in both containers
install_packages(ue_container)
install_packages(dn_container)

# Perform the UDP benchmark
udp_metrics = benchmark_iperf_udp(ue_container, dn_container, dn_ip, bind_address, duration, bandwidth, num_tests)

# Define the CSV filename
iperf_udp_csv_file = 'iperf_udp_metrics.csv'

# Write the results to CSV file
iperf_udp_fieldnames = ['test_num', 'interval', 'bandwidth', 'jitter', 'packet_loss']
write_csv(iperf_udp_csv_file, iperf_udp_fieldnames, udp_metrics)

print("iPerf UDP metrics for each test:", udp_metrics)

# Plot the metrics
plot_metrics(udp_metrics)

