#!/bin/bash

# Deploy 5G Core
echo "Deploying 5G Core..."
docker-compose -f docker-compose-slicing-basic-nrf.yaml up -d --remove-orphans
echo "Deployment completed."
