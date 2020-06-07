#!/bin/bash

# A simple script to bootstrap dependencies

echo "These are the boards connected"
arduino-cli board list

echo "Updating arduino index"
arduino-cli core update-index

echo "Downloading esp8266 dependencies"
arduino-cli core download "esp8266:esp8266"