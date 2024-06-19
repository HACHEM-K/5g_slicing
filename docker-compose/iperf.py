#!/usr/bin/env python3

import subprocess
import threading
import csv

# Function to run iperf client and log output
def run_iperf_client(ue_id, ip_addr):
    log_file = f"ue{ue_id}_iperf.log"
    command = [
        "docker", "exec", f"rfsim5g-oai-nr-ue{ue_id}",
        "iperf", "-c", "192.168.73.146", "-B", ip_addr, "-p", "5001", "-t", "60", "-i", "1"
    ]
    with open(log_file, "w") as f:
        subprocess.run(command, stdout=f, stderr=subprocess.STDOUT)

# Start iperf server
subprocess.Popen(["docker", "exec", "oai-ext-dn", "iperf", "-s", "-i", "1"])

# List of UE IP addresses
ue_ips = [
    "12.1.1.130", "12.1.1.131", "12.1.1.132", "12.1.1.133",
    "12.1.1.134", "12.1.1.135", "12.1.1.136", "12.1.1.137",
    "12.1.1.138", "12.1.1.139", "12.1.1.140", "12.1.1.141",
    "12.1.1.142", "12.1.1.143", "12.1.1.144", "12.1.1.145"
]

# Create and start threads for all iperf clients
threads = []
for i, ip in enumerate(ue_ips, start=1):
    t = threading.Thread(target=run_iperf_client, args=(i, ip))
    threads.append(t)
    t.start()

# Wait for all threads to finish
for t in threads:
    t.join()

# Extract and store bandwidth measurements in a CSV file
with open("bandwidth_measurements.csv", "w", newline='') as csvfile:
    csvwriter = csv.writer(csvfile)
    csvwriter.writerow(["UE ID", "Bandwidth (bits/sec)"])

    for i in range(1, 17):
        ue_id = f"UE{i}"
        bandwidth = None
        with open(f"ue{i}_iperf.log") as f:
            for line in f:
                if "bits/sec" in line:
                    bandwidth = line.strip().split()[-2] + " " + line.strip().split()[-1]
        csvwriter.writerow([ue_id, bandwidth])

print("Bandwidth measurements have been saved to bandwidth_measurements.csv")

