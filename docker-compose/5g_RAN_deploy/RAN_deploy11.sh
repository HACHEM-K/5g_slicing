#!/bin/bash

# Deploy Ran Part
echo "Deploying GNB Part..."
docker-compose -f docker-compose-slicing-ransim.yaml up -d oai-gnb 
echo "Deploying UE Part..."
echo "Deploying UE1"
docker-compose -f docker-compose-slicing-ransim.yaml up -d  oai-nr-ue1
sleep 5
echo "Deploying UE2"
docker-compose -f docker-compose-slicing-ransim.yaml up -d  oai-nr-ue2
sleep 5
echo "Deploying UE3"
docker-compose -f docker-compose-slicing-ransim.yaml up -d  oai-nr-ue3
sleep 5
echo "Deploying UE4"
docker-compose -f docker-compose-slicing-ransim.yaml up -d  oai-nr-ue4
sleep 5
echo "Deploying UE5"
docker-compose -f docker-compose-slicing-ransim.yaml up -d  oai-nr-ue5
sleep 5
echo "Deploying UE6"
docker-compose -f docker-compose-slicing-ransim.yaml up -d  oai-nr-ue6
sleep 5
echo "Deploying UE7"
docker-compose -f docker-compose-slicing-ransim.yaml up -d  oai-nr-ue7
sleep 5
echo "Deploying UE8"
docker-compose -f docker-compose-slicing-ransim.yaml up -d  oai-nr-ue8
sleep 5
echo "Deploying UE9"
docker-compose -f docker-compose-slicing-ransim.yaml up -d  oai-nr-ue9
sleep 5
echo "Deploying UE10"
docker-compose -f docker-compose-slicing-ransim.yaml up -d  oai-nr-ue10
sleep 5
echo "Deploying UE11"
docker-compose -f docker-compose-slicing-ransim.yaml up -d  oai-nr-ue11
sleep 5
echo "RAN Deployment completed."
