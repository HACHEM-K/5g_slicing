#!/bin/bash

# Undeploy 5G RAN
echo "undeploying 5G RAN..."
docker-compose -f docker-compose-slicing-ransim.yaml down -t 0
sleep 5
echo "undeployment completed."
