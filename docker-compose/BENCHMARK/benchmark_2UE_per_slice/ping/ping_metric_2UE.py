#!/usr/bin/env python3

import subprocess
import re
import csv
import os
import threading

def run_command_in_container(container, command):
    print(f"Running command in container {container}: {' '.join(command)}")  # Debug print
    result = subprocess.run(['docker', 'exec', container] + command, capture_output=True, text=True)
    if result.returncode != 0:
        print(f"Command failed in container {container}: {result.stderr}")
    else:
        print(f"Command output in container {container}: {result.stdout}")
    return result.stdout

def parse_ping(output, ue_container):
    packet_stats = []
    print("Ping Output:", output)  # Debug print to see the raw ping output
    
    packet_loss_match = re.search(r'(\d+)% packet loss', output)
    if not packet_loss_match:
        print("Failed to find packet loss in ping output")
        return packet_stats
    
    packet_loss = packet_loss_match.group(1)
    
    rtt_values = re.search(r'rtt min/avg/max/mdev = ([\d\.]+)/([\d\.]+)/([\d\.]+)/([\d\.]+) ms', output)
    if not rtt_values:
        print("Failed to find rtt values in ping output")
        return packet_stats
    
    matches = re.findall(r'icmp_seq=(\d+) ttl=\d+ time=([\d\.]+) ms', output)
    for seq, time in matches:
        packet_stats.append({
            'icmp_seq': int(seq),
            'rtt': float(time),
            'packet_loss': float(packet_loss),
            'rtt_min': float(rtt_values.group(1)),
            'rtt_avg': float(rtt_values.group(2)),
            'rtt_max': float(rtt_values.group(3)),
            'rtt_mdev': float(rtt_values.group(4)),
            'ue_container': ue_container  # Add UE container name
        })
    
    return packet_stats

def benchmark_ping(ue_container, dn_ip, interface):
    print(f"Benchmarking ping for {ue_container} on interface {interface} to {dn_ip}")
    ping_output = run_command_in_container(ue_container, ['ping', '-c', '15', '-I', interface, dn_ip])
    if "ping: unknown host" in ping_output or "connect: Network is unreachable" in ping_output:
        print(f"Ping failed for {ue_container} to {dn_ip}")
        return []
    ping_metrics = parse_ping(ping_output, ue_container)
    if not ping_metrics:
        print(f"No ping metrics found for {ue_container}")
    return ping_metrics

def write_csv(filename, fieldnames, data_list):
    file_exists = os.path.isfile(filename)
    with open(filename, mode='a', newline='') as file:
        writer = csv.DictWriter(file, fieldnames=fieldnames)
        if not file_exists:
            writer.writeheader()
        writer.writerows(data_list)

def run_ping_test(ue_container, dn_ip, interface, csv_file, fieldnames):
    print(f"Starting ping test for {ue_container}")
    ping_metrics = benchmark_ping(ue_container, dn_ip, interface)
    if ping_metrics:
        write_csv(csv_file, fieldnames, ping_metrics)
    print(f"Ping metrics for {ue_container}:", ping_metrics)

# Example usage:
ue_container1 = 'rfsim5g-oai-nr-ue1'  # First UE container name
ue_container2 = 'rfsim5g-oai-nr-ue11' # Second UE container name
dn_ip = '192.168.70.145'              # IP address of the DN container for both UEs
interface = 'oaitun_ue1'              # Interface name for both UEs

# Define the CSV filename
ping_csv_file = 'ping_metrics.csv'

# Define the CSV fieldnames
ping_fieldnames = ['icmp_seq', 'rtt', 'packet_loss', 'rtt_min', 'rtt_avg', 'rtt_max', 'rtt_mdev', 'ue_container']

# Create threads for simultaneous ping tests
thread1 = threading.Thread(target=run_ping_test, args=(ue_container1, dn_ip, interface, ping_csv_file, ping_fieldnames))
thread2 = threading.Thread(target=run_ping_test, args=(ue_container2, dn_ip, interface, ping_csv_file, ping_fieldnames))

# Start the threads
thread1.start()
thread2.start()

# Wait for both threads to finish
thread1.join()
thread2.join()

print("Simultaneous ping tests completed.")

