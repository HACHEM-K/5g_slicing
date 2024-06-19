#!/bin/bash

# Check health of RAN Part
echo "Checking health of RAN Part..."
docker-compose -f docker-compose-slicing-ransim.yaml ps -a
sleep 5

# Check health of 5G Core
echo "Checking health of 5G Core..."
docker-compose -f docker-compose-slicing-basic-nrf.yaml ps -a
sleep 5
