#!/usr/bin/env python3

import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

# Read the CSV file
ping_csv_file = 'ping_metrics.csv'
data = pd.read_csv(ping_csv_file)

# Extract RTT and packet loss values
rtt = data['rtt'].to_numpy()
packet_loss = data['packet_loss'].to_numpy()

# Calculate quartiles for RTT
Q1 = np.percentile(rtt, 25)
median = np.percentile(rtt, 50)
Q3 = np.percentile(rtt, 75)
min_rtt = rtt.min()
max_rtt = rtt.max()

# Display quartile values
print(f"Minimum RTT: {min_rtt} ms")
print(f"Q1 (25th percentile): {Q1} ms")
print(f"Median (50th percentile): {median} ms")
print(f"Q3 (75th percentile): {Q3} ms")
print(f"Maximum RTT: {max_rtt} ms")
print(f"Packet Loss: {packet_loss.mean()} %")

# Create a figure and a set of subplots for RTT
fig, ax1 = plt.subplots(figsize=(12, 8))

# Create a box plot for RTT values
ax1.boxplot(rtt, vert=False, patch_artist=True, boxprops=dict(facecolor='lightblue'))

# Add title and labels
ax1.set_title('Ping RTT Box Plot')
ax1.set_xlabel('RTT (ms)')
ax1.set_yticks([1])
ax1.set_yticklabels(['RTT'])

# Add grid
ax1.grid(True)

# Annotate the quartile values on the plot
ax1.annotate(f'Q1: {Q1} ms', xy=(Q1, 1), xytext=(Q1, 1.1), 
             arrowprops=dict(facecolor='black', shrink=0.05), fontsize=12, ha='center')
ax1.annotate(f'Median: {median} ms', xy=(median, 1), xytext=(median, 1.2), 
             arrowprops=dict(facecolor='black', shrink=0.05), fontsize=12, ha='center')
ax1.annotate(f'Q3: {Q3} ms', xy=(Q3, 1), xytext=(Q3, 1.1), 
             arrowprops=dict(facecolor='black', shrink=0.05), fontsize=12, ha='center')

# Save the RTT plot to file
plt.savefig('ping_rtt_boxplot.png')

# Show the RTT plot
plt.show()

# Create a figure and a set of subplots for packet loss
fig, ax2 = plt.subplots(figsize=(12, 8))

# Plot packet loss
ax2.plot(packet_loss, marker='x', linestyle='--', color='r', label='Packet Loss')
ax2.set_title('Packet Loss Over Time')
ax2.set_xlabel('Ping Sequence')
ax2.set_ylabel('Packet Loss (%)', color='r')
ax2.tick_params(axis='y', labelcolor='r')

# Add grid
ax2.grid(True)

# Save the packet loss plot to file
plt.savefig('ping_packet_loss.png')

# Show the packet loss plot
plt.show()

