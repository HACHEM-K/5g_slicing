#!/bin/bash

# Deploy Ran Part
echo "Deploying Ran Part..."
docker-compose -f docker-compose-slicing-ransim11.yaml up -d ueransim
sleep 5
echo "RAN Deployment completed."
