#!/usr/bin/env python3

import pandas as pd
import matplotlib.pyplot as plt

# Read the CSV file
ping_csv_file = 'ping_metrics.csv'
data = pd.read_csv(ping_csv_file)

# Separate data for each UE container
data_ue1 = data[data['ue_container'] == 'rfsim5g-oai-nr-ue1']
data_ue11 = data[data['ue_container'] == 'rfsim5g-oai-nr-ue11']
data_ue111 = data[data['ue_container'] == 'rfsim5g-oai-nr-ue111']  # Data for the new UE

# Convert columns to numpy arrays for each UE
icmp_seq_ue1 = data_ue1['icmp_seq'].to_numpy()
rtt_ue1 = data_ue1['rtt'].to_numpy()
packet_loss_ue1 = data_ue1['packet_loss'].to_numpy()

icmp_seq_ue11 = data_ue11['icmp_seq'].to_numpy()
rtt_ue11 = data_ue11['rtt'].to_numpy()
packet_loss_ue11 = data_ue11['packet_loss'].to_numpy()

icmp_seq_ue111 = data_ue111['icmp_seq'].to_numpy()  # New UE
rtt_ue111 = data_ue111['rtt'].to_numpy()            # New UE
packet_loss_ue111 = data_ue111['packet_loss'].to_numpy()  # New UE

# Calculate the average RTT for each UE
average_rtt_ue1 = rtt_ue1.mean()
average_rtt_ue11 = rtt_ue11.mean()
average_rtt_ue111 = rtt_ue111.mean()  # New UE

# Create a figure and a set of subplots
fig, ax1 = plt.subplots(figsize=(12, 8))

# Plot RTT vs ICMP Sequence Number for each UE
ax1.set_xlabel('ICMP Sequence Number')
ax1.set_ylabel('RTT (ms)', color='tab:blue')
ax1.plot(icmp_seq_ue1, rtt_ue1, marker='o', linestyle='-', color='tab:blue', label='RTT UE1')
ax1.plot(icmp_seq_ue11, rtt_ue11, marker='^', linestyle='-', color='tab:green', label='RTT UE11')
ax1.plot(icmp_seq_ue111, rtt_ue111, marker='s', linestyle='-', color='tab:purple', label='RTT UE111')  # New UE
ax1.legend(loc='upper left')
ax1.tick_params(axis='y', labelcolor='tab:blue')

# Create a secondary Y-axis to plot packet loss for each UE
ax2 = ax1.twinx()
ax2.set_ylabel('Packet Loss (%)', color='tab:red')
ax2.plot(icmp_seq_ue1, packet_loss_ue1, 'x--', color='tab:red', label='Packet Loss UE1')
ax2.plot(icmp_seq_ue11, packet_loss_ue11, 's--', color='tab:orange', label='Packet Loss UE11')
ax2.plot(icmp_seq_ue111, packet_loss_ue111, 'd--', color='tab:gray', label='Packet Loss UE111')  # New UE
ax2.legend(loc='upper right')
ax2.tick_params(axis='y', labelcolor='tab:red')

# Add average RTT as text on the plot for all UEs
textstr = f'Average RTT UE1: {average_rtt_ue1:.2f} ms\nAverage RTT UE11: {average_rtt_ue11:.2f} ms\nAverage RTT UE111: {average_rtt_ue111:.2f} ms'
props = dict(boxstyle='round', facecolor='wheat', alpha=0.5)
ax1.text(0.05, 0.95, textstr, transform=ax1.transAxes, fontsize=14, verticalalignment='top', bbox=props)

# Add title and grid
plt.title('Ping Metrics Comparison for Multiple UEs', pad=20)
fig.tight_layout()
plt.grid(True)

# Show the plot and save to file
plt.savefig('rtt_packet_loss_comparison.png')
plt.show()

