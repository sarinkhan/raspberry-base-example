#!/bin/bash

while true
do
DATE=$(date +"%Y-%m-%d_%H%M")
raspistill -vf -hf -o $DATE.jpg
sleep 60
done
