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

// Define Soil pin
const int soilMoisturePin = A0;
int moisturePercentage;  // Moisture reading converted to a percentage

// We will use the agriculture feed from Adafruit IO as the way to display data
Adafruit_MQTT_PublishAgricultureData = Adafruit_MQTT_Publish(&mqtt,MQTT_NAME "/f/AgricultureData");

// setting up data feed
Adafruit_MQTT_Client mqtt(&client, MQTT_SERV, MQTT_PORT, MQTT_NAME, MQTT_PASS);

// Added display setup and also wifi connection error message
void setup()
{
  Serial.begin(115200);
  delay(10); // 10 milliseconds delay
  Serial.println("Connecting to ESP"); // Connection message
  Serial.println(ssid);
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print("");  // Prints until not connected
   }
  Serial.println("WiFi connected");
  display.init();
  display.flipScreenVertically();
  display.setFont(ArialMT_Plain_10);
}

void loop()
{
  MQTT_connect();
  moisturePercentage = (100 -((analogRead(soilMoisturePin)/1023.00)*100));
  Serial.print("Soil Moisture is ="); // calculating and printing the percentage
  Serial.print(moisturePercentage);
  Serial.println("%");
  display.clear();
  display.setTextAlignment(TEXT_ALIGN_RIGHT); // moves text to right side of screen
  display.drawString(10, 128, String(millis()));
  display.setTextAlignment(TEXT_ALIGN_LEFT);
  display.setFont(ArialMT_Plain_24);
  display.drawString(50, 0, "Soil");
  display.drawString(25, 20, "Moisture");
  String data1 = String(moisturePercentage);
  display.drawString(45, 40, data1);
  display.drawString(60, 40, "0%");
  display.display();
    if(! AgricultureData.publish(moisturePercentage)) // to publish the moisture percentage variable on adafruit IO
    {
      delay(5000); // 5 second delay 
    }
  delay(6000);
  }
    void MQTT_connect()
  {
    int8_t ret; // Stops if already connected
    if (mqtt.connected())
    {
      return;
    }
    uint8_t retries = 3;
    while ((ret = mqtt.connect())!= 0) // Connect will return to 0 when connected
    {
      mqtt.disconnect();
      delay(5000); // Waiting 5 seconds
      retries--;
      if (retries == 0)
      {
        while(1);
      }
    }
}