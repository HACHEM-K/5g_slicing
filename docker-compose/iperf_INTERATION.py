#!/usr/bin/env python3

import subprocess
import threading
import csv
import os
import time

# Function to run iperf client and log output
def run_iperf_client(ue_id, ip_addr, step):
    log_file = f"measurement/ue{ue_id}_iperf_step{step}.log"
    command = [
        "docker", "exec", f"rfsim5g-oai-nr-ue{ue_id}",
        "iperf", "-c", "192.168.70.145", "-B", ip_addr, "-p", "5001", "-t", "60", "-i", "1"
    ]
    with open(log_file, "w") as f:
        subprocess.run(command, stdout=f, stderr=subprocess.STDOUT)

# Create measurement directory if it doesn't exist
os.makedirs("measurement", exist_ok=True)

# List of UE IP addresses
ue_ips = [
    "12.1.1.130", "12.1.1.131", "12.1.1.132", "12.1.1.133",
    "12.1.1.134", "12.1.1.135", "12.1.1.136", "12.1.1.137",
    "12.1.1.138", "12.1.1.139", "12.1.1.140", "12.1.1.141",
    "12.1.1.142", "12.1.1.143", "12.1.1.144", "12.1.1.145"
]

# Start iperf server
subprocess.Popen(["docker", "exec", "oai-ext-dn", "iperf", "-s", "-i", "1"])

# Perform 5 steps
for step in range(1, 6):
    print(f"Starting step {step}")

    # Create and start threads for all iperf clients
    threads = []
    for i, ip in enumerate(ue_ips, start=1):
        t = threading.Thread(target=run_iperf_client, args=(i, ip, step))
        threads.append(t)
        t.start()

    # Wait for all threads to finish
    for t in threads:
        t.join()

    # Wait for a short period before the next step
    time.sleep(10)

# Extract and store bandwidth measurements in a CSV file
csv_file = "measurement/bandwidth_measurements.csv"
with open(csv_file, "w", newline='') as csvfile:
    csvwriter = csv.writer(csvfile)
    csvwriter.writerow(["Step", "UE ID", "Bandwidth (bits/sec)"])

    for step in range(1, 6):
        for i in range(1, 17):
            ue_id = f"UE{i}"
            bandwidth = None
            log_file = f"measurement/ue{i}_iperf_step{step}.log"
            with open(log_file) as f:
                for line in f:
                    if "bits/sec" in line:
                        bandwidth = line.strip().split()[-2] + " " + line.strip().split()[-1]
            csvwriter.writerow([step, ue_id, bandwidth])

print(f"Bandwidth measurements have been saved to {csv_file}")

