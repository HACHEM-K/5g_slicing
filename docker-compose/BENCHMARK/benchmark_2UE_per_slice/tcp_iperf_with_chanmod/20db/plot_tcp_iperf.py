#!/usr/bin/env python3
import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns

# Correct the file path to match your environment
csv_file_path = '/home/khalid/Bureau/oai-cn5g-fed/docker-compose/iperf_tcp_metrics.csv'

# Load the data from the CSV file
df = pd.read_csv(csv_file_path)

# Convert ue_container to a categorical variable
df['ue_container'] = df['ue_container'].astype('category')

# Plotting
plt.figure(figsize=(16, 10))
axes = sns.boxplot(x='ue_container', y='bitrate', data=df, palette="Set3", linewidth=2, fliersize=5, width=0.6)

# Add jittered data points
sns.stripplot(x='ue_container', y='bitrate', data=df, color='black', jitter=0.2, size=5, alpha=0.6)

# Add quartile values to the plot
def add_quartiles(axes, df):
    for container in df['ue_container'].unique():
        quartiles = df[df['ue_container'] == container]['bitrate'].quantile([0.25, 0.5, 0.75])
        container_index = df['ue_container'].cat.categories.tolist().index(container)
        for q, value in zip(['25%', '50%', '75%'], quartiles):
            # Offset the text slightly to avoid overlap
            offset = 0.05 if q == '50%' else 0.15
            axes.text(
                x=container_index,
                y=value + offset,
                s=f'{q}: {value:.2f}',
                ha='center',
                va='center',
                fontweight='bold',
                color='black',
                backgroundcolor='white',
                bbox=dict(facecolor='white', edgecolor='black', boxstyle='round,pad=0.3')
            )

add_quartiles(axes, df)

plt.title('Bitrate Distribution per UE Container', fontsize=16)
plt.xlabel('UE Container', fontsize=14)
plt.ylabel('Bitrate (Mbits/sec)', fontsize=14)
plt.ylim(0, df['bitrate'].max() * 1.5)  # Adjust the y-axis limit for a bigger scale
plt.xticks(rotation=45, fontsize=12)
plt.yticks(fontsize=12)
plt.grid(True, linestyle='--', alpha=0.7)
plt.tight_layout()
plt.show()

