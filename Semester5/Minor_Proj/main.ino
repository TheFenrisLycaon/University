#include <Wire.h>
#include "MAX30105.h"
#include <WiFi.h>
#include <ThingSpeak.h>
#include "heartRate.h"

const char ssid[] = "Hitu";
const char password[] = "1234567890abc";
const long CHANNEL = 1547155;
const char *WRITE_API = "SE1JB3M4C28XXLBT";
const byte RATE_SIZE = 4; //Increase this for more averaging. 4 is good.

WiFiClient client;
MAX30105 particleSensor;
byte rates[RATE_SIZE]; //Array of heart rates
byte rateSpot = 0;

long lastBeat = 0; //Time at which the last beat occurred
float beatsPerMinute;
int beatAvg;

void setup()
{
  Serial.begin(115200);
  Serial.println("Initializing...");

  // Initialize sensor
  if (!particleSensor.begin(Wire, I2C_SPEED_FAST)) //Use default I2C port, 400kHz speed
  {
    Serial.println("MAX30105 was not found. Please check wiring/power. ");
    while (1)
      ;
  }

  Serial.println("Place your index finger on the sensor with steady pressure.");
  particleSensor.setup();                    //Configure sensor with default settings
  particleSensor.setPulseAmplitudeRed(0x0A); //Turn Red LED to low to indicate sensor is running
  particleSensor.setPulseAmplitudeGreen(0);  //Turn off Green LED
  Serial.println();

  Serial.println("Send Sensor's Data to ThingSpeak Using ESP32");
  Serial.println();

  WiFi.mode(WIFI_STA);
  ThingSpeak.begin(client);
}

void loop()
{
  if (WiFi.status() != WL_CONNECTED)
  {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    while (WiFi.status() != WL_CONNECTED)
    {
      WiFi.begin(ssid, password);
      Serial.print(".");
      delay(5000);
    }
    Serial.println("\nConnected.");
  }

  long irValue = particleSensor.getIR();
  if (checkForBeat(irValue) == true)
  {
    long delta = millis() - lastBeat;
    lastBeat = millis();
    beatsPerMinute = 60 / (delta / 1000.0);
    if (beatsPerMinute < 255 && beatsPerMinute > 20)
    {
      rates[rateSpot++] = (byte)beatsPerMinute; //Store this reading in the array
      rateSpot %= RATE_SIZE;                    //Wrap variable
      beatAvg = 0;
      for (byte x = 0; x < RATE_SIZE; x++)
        beatAvg += rates[x];
      beatAvg /= RATE_SIZE;
    }
  }

  Serial.print("IR=");
  Serial.print(irValue);

  ThingSpeak.setField(1, irValue);
  Serial.print(", BPM=");
  ThingSpeak.setField(2, beatsPerMinute);

  Serial.print(beatsPerMinute);
  Serial.print(", Avg BPM=");
  Serial.print(beatAvg);
  ThingSpeak.setField(3, beatAvg);

  int x = ThingSpeak.writeFields(CHANNEL, WRITE_API);

  if (irValue < 50000)
    Serial.print(" No finger?");
  Serial.println();
}