#!/usr/bin/env python3

import pandas as pd
import matplotlib.pyplot as plt
import os

# Define the directory to save the plot
output_dir = 'output_plots'
if not os.path.exists(output_dir):
    os.makedirs(output_dir)

# Define the CSV filename
csv_file = 'parallel_iperf_tcp_metrics.csv'

# Read the CSV file
data = pd.read_csv(csv_file)

# Create a box plot for each port in the same graph
plt.figure(figsize=(14, 8))

ports = data['port'].unique()
data_to_plot = [data[data['port'] == port]['bitrate'] for port in ports]

box = plt.boxplot(data_to_plot, patch_artist=True, boxprops=dict(facecolor='lightblue'), showmeans=True)

# Adding titles and labels
plt.xlabel('Port')
plt.ylabel('Bitrate (Mbits/sec)')
plt.title('Distribution of Bitrate Measurements by Port')
plt.xticks(range(1, len(ports) + 1), ports)

# Add grid
plt.grid(True)

# Calculate and annotate the quartile values
for i, port in enumerate(ports):
    quartiles = data_to_plot[i].quantile([0.25, 0.5, 0.75])
    Q1 = quartiles[0.25]
    median = quartiles[0.5]
    Q3 = quartiles[0.75]

    plt.annotate(f'Q1: {Q1:.2f} Mbps', xy=(i + 1, Q1), xytext=(i + 1.2, Q1 - 1),
                 arrowprops=dict(facecolor='black', shrink=0.05), fontsize=10, ha='left', va='center')
    plt.annotate(f'Median: {median:.2f} Mbps', xy=(i + 1, median), xytext=(i + 1.2, median),
                 arrowprops=dict(facecolor='black', shrink=0.05), fontsize=10, ha='left', va='center')
    plt.annotate(f'Q3: {Q3:.2f} Mbps', xy=(i + 1, Q3), xytext=(i + 1.2, Q3 + 1),
                 arrowprops=dict(facecolor='black', shrink=0.05), fontsize=10, ha='left', va='center')

# Save the box plot to file
box_plot_path = os.path.join(output_dir, 'bitrate_distribution_boxplot_by_port.png')
plt.tight_layout()
plt.savefig(box_plot_path)

# Show the box plot
plt.show()

print(f"Box plot saved to: {box_plot_path}")

