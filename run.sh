#!/bin/bash
set -e

serial_port=$1
endpoint=$2
ssid=$3
password=$4

board_identifier="esp8266:esp8266:nodemcuv2:xtal=80"

echo "Writing configuration"
echo "const char * ssid=\"$ssid\";" > ./esp8266/values.h
echo "const char * password=\"$password\";" >> ./esp8266/values.h
echo "char * endpoint=\"$endpoint\";" > ./esp8266/endpoint.h

if [[ $endpoint == "https://"* ]]; then
    domain_name=$(echo $endpoint | awk -F[/:] '{print $4}')
    thumb_print_result=$(openssl s_client -connect $domain_name:443 -servername $domain_name < /dev/null 2>/dev/null | openssl x509 -fingerprint -noout -in /dev/stdin)
    thumb_print=$(echo $thumb_print_result | cut -d'=' -f 2)
    echo "char * thumbPrint=\"$thumb_print\";" >> ./esp8266/endpoint.h
else 
    echo "char * thumbPrint=NULL;" >> ./esp8266/endpoint.h
fi;

echo "Compiling code"
arduino-cli compile --fqbn $board_identifier esp8266

echo "Deploying code to $board_identifier on $serial_port"
arduino-cli upload -p $serial_port --fqbn $board_identifier esp8266