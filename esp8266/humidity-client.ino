
#include <ESP8266HTTPClient.h>
#include "Arduino.h"
#include "humidity-client.h"
#include "DHTesp.h"

HumidityClient::HumidityClient()
{
  _humidity = -1000;
  _temperature = -1000;
}

void HumidityClient::setSensor(DHTesp sensor)
{
  _dhtSensor = sensor;
}

void HumidityClient::update()
{
  _humidity = _dhtSensor.getHumidity();
  _temperature = _dhtSensor.getTemperature();
}

float HumidityClient::getHumidity()
{
  return _humidity;
}

float HumidityClient::getTemperature()
{
  return _temperature;
}
