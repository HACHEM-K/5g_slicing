#!/usr/bin/env python3

import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

# Read the CSV file
ping_csv_file = 'ping_metrics.csv'
data = pd.read_csv(ping_csv_file)

# Print the first few rows of the dataframe for debugging
print("Data read from CSV:")
print(data.head())

# Filter data for each UE container
ue1_data = data[data['ue_container'] == 'rfsim5g-oai-nr-ue1']
ue2_data = data[data['ue_container'] == 'rfsim5g-oai-nr-ue11']

# Print the filtered data for debugging
print("UE1 Data:")
print(ue1_data.head())
print("UE2 Data:")
print(ue2_data.head())

# Extract RTT values
ue1_rtt = ue1_data['rtt'].to_numpy()
ue2_rtt = ue2_data['rtt'].to_numpy()

# Print RTT values for debugging
print("UE1 RTT values:")
print(ue1_rtt)
print("UE2 RTT values:")
print(ue2_rtt)

# Calculate quartiles for RTT values
def calculate_quartiles(rtt_values, label):
    Q1 = np.percentile(rtt_values, 25)
    median = np.percentile(rtt_values, 50)
    Q3 = np.percentile(rtt_values, 75)
    min_rtt = rtt_values.min()
    max_rtt = rtt_values.max()
    
    print(f"{label} - Minimum RTT: {min_rtt} ms")
    print(f"{label} - Q1 (25th percentile): {Q1} ms")
    print(f"{label} - Median (50th percentile): {median} ms")
    print(f"{label} - Q3 (75th percentile): {Q3} ms")
    print(f"{label} - Maximum RTT: {max_rtt} ms")

    return Q1, median, Q3

ue1_quartiles = calculate_quartiles(ue1_rtt, "UE1")
ue2_quartiles = calculate_quartiles(ue2_rtt, "UE2")

# Create a figure for RTT box plots
fig, ax1 = plt.subplots(figsize=(12, 8))

# Create box plots for each UE
box = ax1.boxplot([ue1_rtt, ue2_rtt], vert=False, patch_artist=True, labels=['UE1 RTT', 'UE2 RTT'])

# Set colors for each box
colors = ['lightblue', 'lightgreen']
for patch, color in zip(box['boxes'], colors):
    patch.set_facecolor(color)

# Add title and labels
ax1.set_title('Ping RTT Box Plot for Each UE')
ax1.set_xlabel('RTT (ms)')

# Annotate quartiles on the box plot
def annotate_quartiles(ax, quartiles, pos):
    Q1, median, Q3 = quartiles
    ax.annotate(f'Q1: {Q1} ms', xy=(Q1, pos), xytext=(Q1, pos + 0.2), 
                arrowprops=dict(facecolor='black', shrink=0.05), fontsize=12, ha='center')
    ax.annotate(f'Median: {median} ms', xy=(median, pos), xytext=(median, pos + 0.4), 
                arrowprops=dict(facecolor='black', shrink=0.05), fontsize=12, ha='center')
    ax.annotate(f'Q3: {Q3} ms', xy=(Q3, pos), xytext=(Q3, pos + 0.2), 
                arrowprops=dict(facecolor='black', shrink=0.05), fontsize=12, ha='center')

annotate_quartiles(ax1, ue1_quartiles, 1)
annotate_quartiles(ax1, ue2_quartiles, 2)

# Add grid
ax1.grid(True)

# Save the RTT plot to file
plt.savefig('ping_rtt_boxplot.png')

# Show the RTT plot
plt.show()

# Extract packet loss values
ue1_packet_loss = ue1_data['packet_loss'].to_numpy()
ue2_packet_loss = ue2_data['packet_loss'].to_numpy()

# Create a figure for packet loss
fig, ax2 = plt.subplots(figsize=(12, 8))

# Plot packet loss for each UE
ax2.plot(ue1_packet_loss, marker='x', linestyle='--', color='b', label='UE1 Packet Loss')
ax2.plot(ue2_packet_loss, marker='o', linestyle='-', color='g', label='UE2 Packet Loss')

# Add title and labels
ax2.set_title('Packet Loss Over Time for Each UE')
ax2.set_xlabel('Ping Sequence')
ax2.set_ylabel('Packet Loss (%)')
ax2.legend()

# Add grid
ax2.grid(True)

# Save the packet loss plot to file
plt.savefig('ping_packet_loss.png')

# Show the packet loss plot
plt.show()

