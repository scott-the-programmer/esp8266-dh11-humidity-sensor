#ifndef HumidityClient_h
#define HumidityClient_h

#include "Arduino.h"
#include "DHTesp.h"

class HumidityClient
{
public:
  HumidityClient();
  float getHumidity();
  float getTemperature();
  void update();
  void setSensor(DHTesp sensor);

private:
  DHTesp _dhtSensor;
  float _humidity;
  float _temperature;
};

#endif