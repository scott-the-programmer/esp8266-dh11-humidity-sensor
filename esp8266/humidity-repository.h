#ifndef HumidityRepository_h
#define HumidityRepository_h

#include "Arduino.h"
#include "DHTesp.h"

class HumidityRepository
{
public:
  HumidityRepository();
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