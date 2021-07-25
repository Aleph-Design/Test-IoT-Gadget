#include <Arduino.h>
#include <sensorReading.h>

// SPIFFS and FS dependancy is 'included' in TFT_eSPI library
//
#include <TFT_eSPI.h>

TFT_eSPI tft = TFT_eSPI();

void setup() 
{
  Serial.begin(115200);
  vTaskDelay(500 / portTICK_PERIOD_MS);

} // end setup() -------------------------------------------------------------


void loop() 
{
  // put your main code here, to run repeatedly:
  sensorReading();

  vTaskDelay(3000 / portTICK_PERIOD_MS);

} // end loop() --------------------------------------------------------------