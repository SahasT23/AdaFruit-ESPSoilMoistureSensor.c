Moisture sensor using an LCD screen to display water content percentage and moisture level to my laptop using WiFi.
It uses a resistance-based sensor to calculate the current flow between the two prongs and returns a value to show how much electricity is conducted. Since water volume and conductivity are proportionate, we can calculate a moisture value.

***

## Simulation Image 
![Screenshot from 2024-04-19 08-42-37](https://github.com/SahasT23/AdaFruit-ESPSoilMoistureSensor.c/assets/108793094/47609797-b6c7-42d3-9746-a74eba5c08da)

#### Boilerplate code 

```
#include <WiFi.h>
#include <Wire.h>
#include<SH1106.h>
#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"
const char *ssid =  "WiFi Name";     // Enter your WiFi Name
const char *pass =  "Password";  // Enter your WiFi Password
#define MQTT_SERV "io.adafruit.com"
#define MQTT_PORT 1883
#define MQTT_NAME "User Name"
#define MQTT_PASS "AIO Key"
SH1106 display(0x3c, 21, 22);

void setup()
{
  Serial.begin(115200);
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
   }
  Serial.println("WiFi connected");
  display.init();
  display.flipScreenVertically();
  display.setFont(ArialMT_Plain_10);
}
``` 
