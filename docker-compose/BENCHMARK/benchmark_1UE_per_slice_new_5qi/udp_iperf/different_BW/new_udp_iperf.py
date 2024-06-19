#!/usr/bin/env python3
import re
import subprocess
import pandas as pd
import matplotlib.pyplot as plt

# Function to run a command in a Docker container
def run_command_in_container(container, command):
    full_command = f"docker exec {container} {command}"
    result = subprocess.run(full_command, shell=True, capture_output=True, text=True)
    return result.stdout

# Function to start iperf3 server in the dn_container
def start_iperf_server(dn_container):
    server_command = "iperf3 -s -D"  # -D runs the server in the background
    run_command_in_container(dn_container, server_command)

# Function to stop iperf3 server in the dn_container
def stop_iperf_server(dn_container):
    stop_command = "pkill iperf3"
    run_command_in_container(dn_container, stop_command)

# Function to run iperf3 client from ue_container
def run_iperf(ue_container, dn_ip, bind_address, bandwidth, duration):
    client_command = f"iperf3 -c {dn_ip} -u -B {bind_address} -b {bandwidth}M -t {duration}"
    return run_command_in_container(ue_container, client_command)

# Function to parse iperf3 output
def parse_iperf_output(output):
    jitter_pattern = re.compile(r'(\d+\.\d+) ms')
    packet_loss_pattern = re.compile(r'(\d+)/(\d+) \((\d+\.?\d*)%\)')

    jitter_matches = jitter_pattern.findall(output)
    packet_loss_matches = packet_loss_pattern.findall(output)

    # Jitter values (in ms)
    jitters = [float(j) for j in jitter_matches]

    # Packet loss values
    packet_loss = [float(pl[2]) for pl in packet_loss_matches]

    return jitters, packet_loss

# Define test parameters
ue_container = 'rfsim5g-oai-nr-ue1'
dn_container = 'oai-ext-dn'
dn_ip = '192.168.70.145'
bind_address = '12.1.1.130'
duration = 20
bandwidths = [10, 20, 30, 40]

# Collect data
data = {'Bandwidth (Mbps)': [], 'Jitter (ms)': [], 'Packet Loss (%)': []}

for bw in bandwidths:
    # Start the iperf3 server
    start_iperf_server(dn_container)

    # Run the iperf3 client test
    output = run_iperf(ue_container, dn_ip, bind_address, bw, duration)
    jitters, packet_losses = parse_iperf_output(output)
    
    data['Bandwidth (Mbps)'].extend([bw] * len(jitters))
    data['Jitter (ms)'].extend(jitters)
    data['Packet Loss (%)'].extend(packet_losses)
    
    # Stop the iperf3 server
    stop_iperf_server(dn_container)

# Create DataFrame
df = pd.DataFrame(data)

# Save DataFrame to CSV (optional)
df.to_csv('iperf_udp_results.csv', index=False)

# Create box plots for Jitter and Packet Loss
fig, axes = plt.subplots(1, 2, figsize=(15, 5))

# Jitter Box Plot
jitter_data = [df['Jitter (ms)'][df['Bandwidth (Mbps)'] == bw] for bw in bandwidths]
axes[0].boxplot(jitter_data, labels=bandwidths)
axes[0].set_title('Jitter (ms) by Bandwidth')
axes[0].set_xlabel('Bandwidth (Mbps)')
axes[0].set_ylabel('Jitter (ms)')

# Add jitter data points
for i, bw in enumerate(bandwidths):
    y = df['Jitter (ms)'][df['Bandwidth (Mbps)'] == bw]
    x = [i + 1] * len(y)
    axes[0].scatter(x, y, alpha=0.5)
    
    # Annotate jitter quartiles
    q1 = y.quantile(0.25)
    q2 = y.median()
    q3 = y.quantile(0.75)
    axes[0].annotate(f'Q1: {q1:.2f}', xy=(i + 1, q1), xytext=(i + 1.1, q1),
                     arrowprops=dict(facecolor='black', shrink=0.05), fontsize=8)
    axes[0].annotate(f'Q2: {q2:.2f}', xy=(i + 1, q2), xytext=(i + 1.1, q2),
                     arrowprops=dict(facecolor='black', shrink=0.05), fontsize=8)
    axes[0].annotate(f'Q3: {q3:.2f}', xy=(i + 1, q3), xytext=(i + 1.1, q3),
                     arrowprops=dict(facecolor='black', shrink=0.05), fontsize=8)

# Packet Loss Box Plot
packet_loss_data = [df['Packet Loss (%)'][df['Bandwidth (Mbps)'] == bw] for bw in bandwidths]
axes[1].boxplot(packet_loss_data, labels=bandwidths)
axes[1].set_title('Packet Loss (%) by Bandwidth')
axes[1].set_xlabel('Bandwidth (Mbps)')
axes[1].set_ylabel('Packet Loss (%)')

# Add packet loss data points
for i, bw in enumerate(bandwidths):
    y = df['Packet Loss (%)'][df['Bandwidth (Mbps)'] == bw]
    x = [i + 1] * len(y)
    axes[1].scatter(x, y, alpha=0.5)
    
    # Annotate packet loss quartiles
    q1 = y.quantile(0.25)
    q2 = y.median()
    q3 = y.quantile(0.75)
    axes[1].annotate(f'Q1: {q1:.2f}', xy=(i + 1, q1), xytext=(i + 1.1, q1),
                     arrowprops=dict(facecolor='black', shrink=0.05), fontsize=8)
    axes[1].annotate(f'Q2: {q2:.2f}', xy=(i + 1, q2), xytext=(i + 1.1, q2),
                     arrowprops=dict(facecolor='black', shrink=0.05), fontsize=8)
    axes[1].annotate(f'Q3: {q3:.2f}', xy=(i + 1, q3), xytext=(i + 1.1, q3),
                     arrowprops=dict(facecolor='black', shrink=0.05), fontsize=8)

plt.tight_layout()
plt.show()

