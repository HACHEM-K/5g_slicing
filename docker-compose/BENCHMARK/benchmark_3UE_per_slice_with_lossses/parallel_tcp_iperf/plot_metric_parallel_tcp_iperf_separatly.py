#!/usr/bin/env python3

import pandas as pd
import matplotlib.pyplot as plt

# Define the CSV filename
csv_file = 'parallel_iperf_tcp_metrics.csv'

# Read the CSV file
data = pd.read_csv(csv_file)

# Ensure intervals are sorted correctly for each port
data[['interval_start', 'interval_end']] = data['interval'].str.split('-', expand=True).astype(float)
data = data.sort_values(by=['port', 'interval_start'])

# Calculate the average bitrate
average_bitrate = data['bitrate'].mean()

# Plot bitrate vs interval for each port separately
ports = data['port'].unique()
for port in ports:
    port_data = data[data['port'] == port]
    intervals = port_data['interval'].to_numpy()
    bitrates = port_data['bitrate'].to_numpy()
    
    plt.figure(figsize=(10, 6))
    plt.plot(intervals, bitrates, marker='o', linestyle='-', label=f'Port {port} Bitrate (Mbits/sec)')
    plt.xlabel('Interval (sec)')
    plt.ylabel('Bitrate (Mbits/sec)')
    plt.title(f'Parallel iPerf Bitrate vs Interval for Port {port}\nAverage Bitrate: {average_bitrate:.2f} Mbits/sec')
    plt.xticks(rotation=45)
    plt.grid(True)
    plt.legend()
    plt.tight_layout()
    plt.savefig(f'parallel_iperf_bitrate_vs_interval_port_{port}.png')
    plt.show()

    print(f"Average Bitrate for Port {port}: {average_bitrate:.2f} Mbits/sec")

