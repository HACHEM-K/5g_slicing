#!/usr/bin/env python3

import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

# Define the CSV filename
csv_file = 'iperf_tcp_metrics.csv'

# Read the CSV file
data = pd.read_csv(csv_file)

# Convert columns to numpy arrays
intervals = data['interval'].to_numpy()
bitrates = data['bitrate'].to_numpy()

# Calculate the average bitrate
average_bitrate = bitrates.mean()

# Plot bitrate vs interval (line plot)
plt.figure(figsize=(12, 6))
plt.plot(intervals, bitrates, marker='o', linestyle='-', color='b', label='Bitrate (Mbits/sec)')
plt.xlabel('Interval (sec)')
plt.ylabel('Bitrate (Mbits/sec)')
plt.title(f'Bitrate vs Interval\nAverage Bitrate: {average_bitrate:.2f} Mbits/sec')
plt.xticks(rotation=45)
plt.grid(True)
plt.legend()
plt.tight_layout()
plt.savefig('bitrate_vs_interval.png')
plt.show()

print(f"Average Bitrate: {average_bitrate:.2f} Mbits/sec")

# Calculate quartiles for bitrate
Q1 = np.percentile(bitrates, 25)
median = np.percentile(bitrates, 50)
Q3 = np.percentile(bitrates, 75)
min_bitrate = bitrates.min()
max_bitrate = bitrates.max()

# Display quartile values
print(f"Minimum Bitrate: {min_bitrate} Mbps")
print(f"Q1 (25th percentile): {Q1} Mbps")
print(f"Median (50th percentile): {median} Mbps")
print(f"Q3 (75th percentile): {Q3} Mbps")
print(f"Maximum Bitrate: {max_bitrate} Mbps")

# Create a box plot for the distribution of bitrate
fig, ax = plt.subplots(figsize=(12, 6))
ax.boxplot(bitrates, vert=False, patch_artist=True, boxprops=dict(facecolor='lightblue'))
ax.set_xlabel('Bitrate (Mbits/sec)')
ax.set_title('Distribution of Bitrate Measurements')
ax.grid(True)

# Annotate the quartile values on the plot
ax.annotate(f'Q1: {Q1:.2f} Mbps', xy=(Q1, 1), xytext=(Q1, 1.1),
             arrowprops=dict(facecolor='black', shrink=0.05), fontsize=12, ha='center')
ax.annotate(f'Median: {median:.2f} Mbps', xy=(median, 1), xytext=(median, 1.2),
             arrowprops=dict(facecolor='black', shrink=0.05), fontsize=12, ha='center')
ax.annotate(f'Q3: {Q3:.2f} Mbps', xy=(Q3, 1), xytext=(Q3, 1.1),
             arrowprops=dict(facecolor='black', shrink=0.05), fontsize=12, ha='center')

# Save the box plot to file
plt.tight_layout()
plt.savefig('bitrate_distribution_boxplot.png')

# Show the box plot
plt.show()

