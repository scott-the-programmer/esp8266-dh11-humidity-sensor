
#include <ESP8266HTTPClient.h>
#include "Arduino.h"
#include "api-repository.h"
#include "DHTesp.h"

HumidityRepository::HumidityRepository()
{
  _humidity = -1000;
  _temperature = -1000;
}

void HumidityRepository::setSensor(DHTesp sensor)
{
  _dhtSensor = sensor;
}

void HumidityRepository::update()
{
  _humidity = _dhtSensor.getHumidity();
  _temperature = _dhtSensor.getTemperature();
}

float HumidityRepository::getHumidity()
{
  return _humidity;
}

float HumidityRepository::getTemperature()
{
  return _temperature;
}
