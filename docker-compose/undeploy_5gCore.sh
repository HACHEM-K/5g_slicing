#!/bin/bash

# Undeploy 5G Core
echo "Undeploying 5G Core..."
docker-compose -f docker-compose-slicing-basic-nrf.yaml down -v -t 0
if [ $? -eq 0 ]; then
    echo "Undeployment completed successfully."

    # Remove unused volumes
    echo "Removing unused Docker volumes..."
    docker volume prune -f
    echo "Unused volumes removed."
else
    echo "Undeployment failed. Please check the logs."
fi
sleep 5

