#!/usr/bin/env python3

import pandas as pd
import matplotlib.pyplot as plt

# Define the CSV filename
csv_file = 'iperf_tcp_metrics.csv'

# Read the CSV file
data = pd.read_csv(csv_file)

# Convert columns to numpy arrays
intervals = data['interval'].to_numpy()
bitrates = data['bitrate'].to_numpy()

# Calculate the average bitrate
average_bitrate = bitrates.mean()

# Plot bitrate vs interval
plt.figure(figsize=(10, 6))
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

