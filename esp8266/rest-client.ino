
#include <ESP8266HTTPClient.h>
#include "Arduino.h"
#include "rest-client.h"

RestClient::RestClient(char *url, char *thumbPrint)
{
    _url = url;
    _thumbPrint = thumbPrint;
}

bool RestClient::post(String data)
{
    HTTPClient http;

    bool ret = false;

    if (_thumbPrint)
    {
        http.begin(_url, _thumbPrint);
    }
    else
    {
        http.begin(_url);
    }

    http.addHeader("Content-Type", "application/json");

    Serial.println(data);
    int httpCode = http.POST(data);

    if (httpCode >= 200 && httpCode < 300) //Returned successful error code
    {
        ret = true;
    }

    Serial.print("HTTP Response code: ");
    Serial.println(httpCode);

    http.end();

    return ret;
}
