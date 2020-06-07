#include <ESP8266WiFi.h>
#include "api-repository.h"
#include "humidity-repository.h"
#include "endpoint.h"
#include "values.h"
#include "DHTesp.h"

DHTesp dht;

ApiRepository api = ApiRepository(endpoint, thumbPrint);
HumidityRepository humid = HumidityRepository();

void setup()
{
    setupLed();
    setupSerial();
    setupWifi();
    setupSensor();
}

void loop()
{
    if (WiFi.status() != WL_CONNECTED)
    {
        return;
    }

    humid.update();

    Serial.println(humid.getHumidity(), 1);
    String humidity = String(humid.getHumidity());
    String data = "{\"HumidityPercentage\": " + humidity + " }";

    api.post(data);
    delay(2000);
}

void setupLed()
{
    pinMode(LED_BUILTIN, OUTPUT);
}

void setupSerial()
{

    Serial.begin(9600);
    while (!Serial)
    {
        ; // wait for serial port to connect. Needed for native USB port only
    }
}

void setupWifi()
{
    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED)
    {
        delay(1000);
        Serial.println("Connecting...");
    }
}

void setupSensor()
{
    dht.setup(13, DHTesp::DHT11); // Connect DHT sensor to GPIO 17
    humid.setSensor(dht);
}