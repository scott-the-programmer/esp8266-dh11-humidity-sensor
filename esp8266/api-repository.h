
#ifndef ApiRepository_h
#define ApiRepository_h

#include "Arduino.h"

class ApiRepository
{
public:
  ApiRepository(char *url, char *thumbPrint);
  bool post(String data);

private:
  char *_url;
  char *_thumbPrint;
};

#endif