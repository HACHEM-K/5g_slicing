#!/usr/bin/env python3

import pandas as pd
import matplotlib.pyplot as plt
import os

# Define the directory to save the plot
output_dir = 'output_plots'
if not os.path.exists(output_dir):
    os.makedirs(output_dir)

# Define the CSV filename
csv_file = 'parallel_iperf_udp_metrics.csv'

# Read the CSV file
data = pd.read_csv(csv_file)

# Create a figure and a set of subplots for bitrate and loss
fig, (ax1, ax2) = plt.subplots(2, 1, figsize=(14, 12))

# Create a box plot for bitrate for each port
ports = data['port'].unique()
bitrate_data_to_plot = [data[data['port'] == port]['bitrate'] for port in ports]
ax1.boxplot(bitrate_data_to_plot, patch_artist=True, boxprops=dict(facecolor='lightblue'), showmeans=True)
ax1.set_xlabel('Port')
ax1.set_ylabel('Bitrate (Mbits/sec)')
ax1.set_title('Distribution of Bitrate Measurements by Port')
ax1.set_xticks(range(1, len(ports) + 1))
ax1.set_xticklabels(ports)
ax1.grid(True)

# Create a box plot for packet loss for each port
loss_data_to_plot = [data[data['port'] == port]['loss'] for port in ports]
ax2.boxplot(loss_data_to_plot, patch_artist=True, boxprops=dict(facecolor='lightcoral'), showmeans=True)
ax2.set_xlabel('Port')
ax2.set_ylabel('Packet Loss (%)')
ax2.set_title('Distribution of Packet Loss by Port')
ax2.set_xticks(range(1, len(ports) + 1))
ax2.set_xticklabels(ports)
ax2.grid(True)

# Calculate and annotate the quartile values for bitrate
for i, port in enumerate(ports):
    quartiles = bitrate_data_to_plot[i].quantile([0.25, 0.5, 0.75])
    Q1 = quartiles[0.25]
    median = quartiles[0.5]
    Q3 = quartiles[0.75]

    ax1.annotate(f'Q1: {Q1:.2f} Mbps', xy=(i + 1, Q1), xytext=(i + 1.2, Q1 - 1),
                 arrowprops=dict(facecolor='black', shrink=0.05), fontsize=10, ha='left', va='center')
    ax1.annotate(f'Median: {median:.2f} Mbps', xy=(i + 1, median), xytext=(i + 1.2, median),
                 arrowprops=dict(facecolor='black', shrink=0.05), fontsize=10, ha='left', va='center')
    ax1.annotate(f'Q3: {Q3:.2f} Mbps', xy=(i + 1, Q3), xytext=(i + 1.2, Q3 + 1),
                 arrowprops=dict(facecolor='black', shrink=0.05), fontsize=10, ha='left', va='center')

# Calculate and annotate the quartile values for loss
for i, port in enumerate(ports):
    quartiles = loss_data_to_plot[i].quantile([0.25, 0.5, 0.75])
    Q1 = quartiles[0.25]
    median = quartiles[0.5]
    Q3 = quartiles[0.75]

    ax2.annotate(f'Q1: {Q1:.2f}%', xy=(i + 1, Q1), xytext=(i + 1.2, Q1 - 1),
                 arrowprops=dict(facecolor='black', shrink=0.05), fontsize=10, ha='left', va='center')
    ax2.annotate(f'Median: {median:.2f}%', xy=(i + 1, median), xytext=(i + 1.2, median),
                 arrowprops=dict(facecolor='black', shrink=0.05), fontsize=10, ha='left', va='center')
    ax2.annotate(f'Q3: {Q3:.2f}%', xy=(i + 1, Q3), xytext=(i + 1.2, Q3 + 1),
                 arrowprops=dict(facecolor='black', shrink=0.05), fontsize=10, ha='left', va='center')

# Save the box plots to file
box_plot_path = os.path.join(output_dir, 'udp_bitrate_loss_boxplot_by_port.png')
plt.tight_layout()
plt.savefig(box_plot_path)

# Show the box plots
plt.show()

print(f"Box plot saved to: {box_plot_path}")

