#!/usr/bin/env python3

import subprocess
import re
import csv
import os
import threading

def run_command_in_container(container, command):
    result = subprocess.run(['docker', 'exec', container] + command, capture_output=True, text=True)
    return result.stdout

def parse_ping(output,ue_container):
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
            'rtt_mdev': float(rtt_values.group(4)),
            'ue_container': ue_container  # Add container name to each metric
        })
    
    return packet_stats

def benchmark_ping(ue_container, dn_ip, interface):
    ping_output = run_command_in_container(ue_container, ['ping', '-c', '15', '-I', interface, dn_ip])
    ping_metrics = parse_ping(ping_output,ue_container)
    return ping_metrics

def write_csv(filename, fieldnames, data_list):
    file_exists = os.path.isfile(filename)
    with open(filename, mode='a', newline='') as file:
        writer = csv.DictWriter(file, fieldnames=fieldnames)
        if not file_exists:
            writer.writeheader()
        writer.writerows(data_list)

def thread_function(ue_container, dn_ip, interface, csv_file, fieldnames):
    ping_metrics = benchmark_ping(ue_container, dn_ip, interface)
    write_csv(csv_file, fieldnames, ping_metrics)
    print(f"Ping metrics for {ue_container}:", ping_metrics)

# List of UE container names now includes the new UE
ue_containers = ['rfsim5g-oai-nr-ue1', 'rfsim5g-oai-nr-ue11', 'rfsim5g-oai-nr-ue111']  
dn_ip = '192.168.70.145'  # IP address of the DN container
interface = 'oaitun_ue1'  # Interface name used for ping

# Define the CSV filename and fieldnames
ping_csv_file = 'ping_metrics.csv'
ping_fieldnames = ['icmp_seq', 'rtt', 'packet_loss', 'rtt_min', 'rtt_avg', 'rtt_max', 'rtt_mdev', 'ue_container']

# Create and start threads for each UE container
threads = []
for ue_container in ue_containers:
    thread = threading.Thread(target=thread_function, args=(ue_container, dn_ip, interface, ping_csv_file, ping_fieldnames))
    threads.append(thread)
    thread.start()

# Wait for all threads to finish
for thread in threads:
    thread.join()

