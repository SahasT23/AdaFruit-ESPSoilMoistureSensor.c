// included the appropriate libraries for using with the AdaFruit simulation
#include <WiFi.h> // for WiFi connection with the board
#include <Wire.h> // reading and writing data (I/O)
#include<SH1106.h>
#include "Adafruit_MQTT.h" // IoT messaging protocol
#include "Adafruit_MQTT_Client.h" 

// WiFi and AdaFruit credentials are copied from the website

const char *ssid =  "WiFi Name";     // Enter your WiFi Name (Hidden)
const char *pass =  "Password";  // Enter your WiFi Password (Hidden)
#define MQTT_SERV "io.adafruit.com"
#define MQTT_PORT 1883
#define MQTT_NAME "User Name" // User name on Adafruit IO website
#define MQTT_PASS "AIO Key" // The key required for establishing connections

SH1106 display(0x3c, 21, 22);

