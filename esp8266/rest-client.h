
#ifndef ApiRepository_h
#define ApiRepository_h

#include "Arduino.h"

class RestClient
{
public:
  RestClient(char *url, char *thumbPrint);
  bool post(String data);

private:
  char *_url;
  char *_thumbPrint;
};

#endif