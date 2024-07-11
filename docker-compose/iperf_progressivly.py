#!/usr/bin/env python3

import subprocess
import threading
import csv
import os
import time

# Function to run iperf client and log output
def run_iperf_client(ue_id, ip_addr):
    log_file = f"measurement/ue{ue_id}_iperf.log"
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

# Perform tests progressively with an increasing number of UEs
for step in range(1, 17):
    print(f"Starting test with {step} UE(s)")

    # Create and start threads for the current number of iperf clients
    threads = []
    for i in range(step):
        t = threading.Thread(target=run_iperf_client, args=(i + 1, ue_ips[i]))
        threads.append(t)
        t.start()

    # Wait for all threads to finish
    for t in threads:
        t.join()

    # Extract and store bandwidth measurements for the current step
    csv_file = f"measurement/bandwidth_measurements_step_{step}.csv"
    with open(csv_file, "w", newline='') as csvfile:
        csvwriter = csv.writer(csvfile)
        csvwriter.writerow(["UE ID", "Bandwidth (bits/sec)"])

        for i in range(1, step + 1):
            ue_id = f"UE{i}"
            bandwidth = None
            log_file = f"measurement/ue{i}_iperf.log"
            with open(log_file) as f:
                for line in f:
                    if "bits/sec" in line:
                        bandwidth = line.strip().split()[-2] + " " + line.strip().split()[-1]
            csvwriter.writerow([ue_id, bandwidth])

    print(f"Bandwidth measurements for {step} UE(s) have been saved to {csv_file}")

    # Wait for a short period before the next step
    time.sleep(10)

print("All bandwidth measurements have been saved.")

