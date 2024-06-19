#!/bin/bash

# Deploy Ran Part
echo "Deploying Ran Part..."
docker-compose -f docker-compose-slicing-ransim.yaml up -d ueransim
sleep 5
docker-compose -f docker-compose-slicing-ransim.yaml up -d oai-gnb oai-nr-ue1
sleep 5
docker-compose -f docker-compose-slicing-ransim.yaml up -d gnbsim
sleep 5
echo "RAN Deployment completed."
