#!/bin/bash

# Start iperf server
docker exec oai-ext-dn iperf -s -i 1 &

# Function to run iperf client
run_iperf_client() {
  ue_id=$1
  ip_addr=$2
  log_file="ue${ue_id}_iperf.log"

  docker exec rfsim5g-oai-nr-ue${ue_id} iperf -c 192.168.73.146 -B ${ip_addr} -p 5001 -t 60 -i 1 > ${log_file}
}

# Create commands array
commands=(
  "run_iperf_client 1 12.1.1.130"
  "run_iperf_client 2 12.1.1.131"
  "run_iperf_client 3 12.1.1.132"
  "run_iperf_client 4 12.1.1.133"
  "run_iperf_client 5 12.1.1.134"
  "run_iperf_client 6 12.1.1.135"
  "run_iperf_client 7 12.1.1.136"
  "run_iperf_client 8 12.1.1.137"
  "run_iperf_client 9 12.1.1.138"
  "run_iperf_client 10 12.1.1.139"
  "run_iperf_client 11 12.1.1.140"
  "run_iperf_client 12 12.1.1.141"
  "run_iperf_client 13 12.1.1.142"
  "run_iperf_client 14 12.1.1.143"
  "run_iperf_client 15 12.1.1.144"
  "run_iperf_client 16 12.1.1.145"
)

# Export the function so it can be used by xargs
export -f run_iperf_client

# Run all iperf clients in parallel
printf "%s\n" "${commands[@]}" | xargs -n 1 -P 16 -I {} bash -c {}

# Extract and display bandwidth measurements
for i in {1..16}; do
  echo "Bandwidth measurement for UE${i}:"
  grep "bits/sec" ue${i}_iperf.log
done

