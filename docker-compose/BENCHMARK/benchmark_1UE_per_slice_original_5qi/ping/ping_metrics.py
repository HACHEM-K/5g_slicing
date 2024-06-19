#!/usr/bin/env python3

import subprocess
import re
import csv
import os

def run_command_in_container(container, command):
    result = subprocess.run(['docker', 'exec', container] + command, capture_output=True, text=True)
    return result.stdout

def parse_ping(output):
    packet_stats = []
    packet_loss = re.search(r'(\d+)% packet loss', output).group(1)
    rtt_values = re.search(r'rtt min/avg/max/mdev = ([\d\.]+)/([\d\.]+)/([\d\.]+)/([\d\.]+) ms', output)
    
    matches = re.findall(r'icmp_seq=(\d+) ttl=\d+ time=([\d\.]+) ms', output)
    for seq, time in matches:
        packet_stats.append({
            'icmp_seq': int(seq),
            'rtt': float(time),
            'packet_loss': float(packet_loss),
            'rtt_min': float(rtt_values.group(1)),
            'rtt_avg': float(rtt_values.group(2)),
            'rtt_max': float(rtt_values.group(3)),
            'rtt_mdev': float(rtt_values.group(4))
        })
    
    return packet_stats

def benchmark_ping(ue_container, dn_ip, interface):
    ping_output = run_command_in_container(ue_container, ['ping', '-c', '15', '-I', interface, dn_ip])
    ping_metrics = parse_ping(ping_output)
    return ping_metrics

def write_csv(filename, fieldnames, data_list):
    file_exists = os.path.isfile(filename)
    with open(filename, mode='a', newline='') as file:
        writer = csv.DictWriter(file, fieldnames=fieldnames)
        if not file_exists:
            writer.writeheader()
        writer.writerows(data_list)

# Example usage:
ue_container = 'rfsim5g-oai-nr-ue1'  # UE container name
dn_ip = '192.168.70.145'             # IP address of the DN container
interface = 'oaitun_ue1'             # Interface name

# Perform the ping benchmark
ping_metrics = benchmark_ping(ue_container, dn_ip, interface)

# Define the CSV filename
ping_csv_file = 'ping_metrics.csv'

# Define the CSV fieldnames
ping_fieldnames = ['icmp_seq', 'rtt', 'packet_loss', 'rtt_min', 'rtt_avg', 'rtt_max', 'rtt_mdev']

# Write the results to CSV file
write_csv(ping_csv_file, ping_fieldnames, ping_metrics)

print("Ping metrics:", ping_metrics)

