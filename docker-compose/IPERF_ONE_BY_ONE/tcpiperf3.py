#!/usr/bin/env python3
import subprocess
import threading
import csv
import re
import time

# Function to run iperf command and store output
def run_iperf(container, ip, bind_ip, port, output_list, ue_id):
    cmd = f"docker exec {container} iperf -c {ip} -B {bind_ip} -p {port} -t 60 -i 1"
    process = subprocess.Popen(cmd, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    stdout, stderr = process.communicate()
    
    # Collect the output in a list
    output = stdout.decode().splitlines()
    output_list.extend(output)


# Lists to store the output
output_ue1 = []
output_ue2 = []
output_ue3 = []

# Create threads to run iperf commands simultaneously
thread_ue1 = threading.Thread(target=run_iperf, args=("rfsim5g-oai-nr-ue1", "192.168.70.145", "12.1.1.130", 5001, output_ue1, "UE 1"))
thread_ue2 = threading.Thread(target=run_iperf, args=("rfsim5g-oai-nr-ue2", "192.168.70.145", "12.1.1.131", 5001, output_ue2, "UE 2"))
thread_ue3 = threading.Thread(target=run_iperf, args=("rfsim5g-oai-nr-ue3", "192.168.70.145", "12.1.1.132", 5001, output_ue3, "UE 3"))

# Start the threads
start_time = time.time()
thread_ue1.start()
thread_ue2.start()
thread_ue3.start()


# Wait for all threads to complete
thread_ue1.join()
thread_ue2.join()
thread_ue3.join()
end_time = time.time()

# Write the output to a CSV file
with open('iperf_results.csv', 'w', newline='') as csvfile:
    csvwriter = csv.writer(csvfile)
    csvwriter.writerow(['Time', 'Container', 'Output'])
    
    # Write output for UE1
    for line in output_ue1:
        csvwriter.writerow([time.strftime("%Y-%m-%d %H:%M:%S", time.localtime(start_time)), "rfsim5g-oai-nr-ue1", line])
    
    # Write output for UE2
    for line in output_ue2:
        csvwriter.writerow([time.strftime("%Y-%m-%d %H:%M:%S", time.localtime(start_time)), "rfsim5g-oai-nr-ue2", line])
        # Write output for UE3
    for line in output_ue3:
        csvwriter.writerow([time.strftime("%Y-%m-%d %H:%M:%S", time.localtime(start_time)), "rfsim5g-oai-nr-ue3", line])
       

print("All iperf commands have completed.")
print("Results are stored in iperf_results.csv")

