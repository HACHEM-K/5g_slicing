#!/usr/bin/env python3
import psutil
import time
import matplotlib.pyplot as plt

def monitor_cpu_usage(duration=60):
    cpu_usages = []
    start_time = time.time()
    while time.time() - start_time < duration:
        cpu_usage = psutil.cpu_percent(interval=1)
        cpu_usages.append(cpu_usage)
        print(f"CPU Usage: {cpu_usage}%")
    return cpu_usages

if __name__ == "__main__":
    print("Monitoring CPU usage for 60 seconds...")
    cpu_usages = monitor_cpu_usage(60)

    # Plotting the CPU usage
    plt.figure(figsize=(12, 6))
    plt.plot(cpu_usages, label="CPU Usage", color='blue')
    plt.xlabel("Time (seconds)")
    plt.ylabel("CPU Usage (%)")
    plt.title("CPU Usage Monitoring")
    plt.legend()
    plt.show()

