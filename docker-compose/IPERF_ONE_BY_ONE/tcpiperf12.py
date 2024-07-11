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
output_ue4 = []
output_ue5 = []
output_ue6 = []
output_ue7 = []
output_ue8 = []
output_ue9 = []
output_ue10 = []
output_ue11 = []
output_ue12 = []

# Create threads to run iperf commands simultaneously
thread_ue1 = threading.Thread(target=run_iperf, args=("rfsim5g-oai-nr-ue1", "192.168.70.145", "12.1.1.130", 5001, output_ue1, "UE 1"))
thread_ue2 = threading.Thread(target=run_iperf, args=("rfsim5g-oai-nr-ue2", "192.168.70.145", "12.1.1.131", 5001, output_ue2, "UE 2"))
thread_ue3 = threading.Thread(target=run_iperf, args=("rfsim5g-oai-nr-ue3", "192.168.70.145", "12.1.1.132", 5001, output_ue3, "UE 3"))
thread_ue4 = threading.Thread(target=run_iperf, args=("rfsim5g-oai-nr-ue4", "192.168.70.145", "12.1.1.133", 5001, output_ue4, "UE 4"))
thread_ue5 = threading.Thread(target=run_iperf, args=("rfsim5g-oai-nr-ue5", "192.168.70.145", "12.1.1.134", 5001, output_ue5, "UE 5"))
thread_ue6 = threading.Thread(target=run_iperf, args=("rfsim5g-oai-nr-ue6", "192.168.70.145", "12.1.1.135", 5001, output_ue6, "UE 6"))
thread_ue7 = threading.Thread(target=run_iperf, args=("rfsim5g-oai-nr-ue7", "192.168.70.145", "12.1.1.136", 5001, output_ue7, "UE 7"))
thread_ue8 = threading.Thread(target=run_iperf, args=("rfsim5g-oai-nr-ue8", "192.168.70.145", "12.1.1.137", 5001, output_ue8, "UE 8"))
thread_ue9 = threading.Thread(target=run_iperf, args=("rfsim5g-oai-nr-ue9", "192.168.70.145", "12.1.1.138", 5001, output_ue9, "UE 9"))
thread_ue10 = threading.Thread(target=run_iperf, args=("rfsim5g-oai-nr-ue10", "192.168.70.145", "12.1.1.139", 5001, output_ue10, "UE 10"))
thread_ue11 = threading.Thread(target=run_iperf, args=("rfsim5g-oai-nr-ue11", "192.168.70.145", "12.1.1.140", 5001, output_ue11, "UE 11"))
thread_ue12 = threading.Thread(target=run_iperf, args=("rfsim5g-oai-nr-ue12", "192.168.70.145", "12.1.1.141", 5001, output_ue12, "UE 12"))

# Start the threads
start_time = time.time()
thread_ue1.start()
thread_ue2.start()
thread_ue3.start()
thread_ue4.start()
thread_ue5.start()
thread_ue6.start()
thread_ue7.start()
thread_ue8.start()
thread_ue9.start()
thread_ue10.start()
thread_ue11.start()
thread_ue12.start()

# Wait for all threads to complete
thread_ue1.join()
thread_ue2.join()
thread_ue3.join()
thread_ue4.join()
thread_ue5.join()
thread_ue6.join()
thread_ue7.join()
thread_ue8.join()
thread_ue9.join()
thread_ue10.join()
thread_ue11.join()
thread_ue12.join()
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
    
    # Write output for UE4
    for line in output_ue4:
        csvwriter.writerow([time.strftime("%Y-%m-%d %H:%M:%S", time.localtime(start_time)), "rfsim5g-oai-nr-ue4", line])
    
    # Write output for UE5
    for line in output_ue5:
        csvwriter.writerow([time.strftime("%Y-%m-%d %H:%M:%S", time.localtime(start_time)), "rfsim5g-oai-nr-ue5", line])
    
    # Write output for UE6
    for line in output_ue6:
        csvwriter.writerow([time.strftime("%Y-%m-%d %H:%M:%S", time.localtime(start_time)), "rfsim5g-oai-nr-ue6", line])
    
    # Write output for UE7
    for line in output_ue7:
        csvwriter.writerow([time.strftime("%Y-%m-%d %H:%M:%S", time.localtime(start_time)), "rfsim5g-oai-nr-ue7", line])
    
    # Write output for UE8
    for line in output_ue8:
        csvwriter.writerow([time.strftime("%Y-%m-%d %H:%M:%S", time.localtime(start_time)), "rfsim5g-oai-nr-ue8", line])
    
    # Write output for UE9
    for line in output_ue9:
        csvwriter.writerow([time.strftime("%Y-%m-%d %H:%M:%S", time.localtime(start_time)), "rfsim5g-oai-nr-ue9", line])
    
    # Write output for UE10
    for line in output_ue10:
        csvwriter.writerow([time.strftime("%Y-%m-%d %H:%M:%S", time.localtime(start_time)), "rfsim5g-oai-nr-ue10", line])
    
    # Write output for UE11
    for line in output_ue11:
        csvwriter.writerow([time.strftime("%Y-%m-%d %H:%M:%S", time.localtime(start_time)), "rfsim5g-oai-nr-ue11", line])
    
    # Write output for UE12
    for line in output_ue12:
        csvwriter.writerow([time.strftime("%Y-%m-%d %H:%M:%S", time.localtime(start_time)), "rfsim5g-oai-nr-ue12", line])

print("All iperf commands have completed.")
print("Results are stored in iperf_results.csv")

