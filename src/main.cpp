#include <Arduino.h>
#include <sensorReading.h>

// tft is not a real global variable; it's only accessible from within the
// functions in THIS file: NOT in ALL files of the C++ application.
// If you want to make it accessible in all files you'll need to make it
// extern like this: 
// extern TFT_eSPI tft = TFT_eSPI();
//
// To avoid using global variables all over the application we use pointers: 
//
TFT_eSPI *pTft = NULL;    // declare the pointer; no memory allocated yet.


void setup() 
{
  Serial.begin(115200);
  vTaskDelay(500 / portTICK_PERIOD_MS);

  // Create an instance of class TFT_eSPI and assign it's address to the
  // pointer. Now we can pass the pointer around and use methods in the
  // class TFT_eSPI.
  //
  pTft = new TFT_eSPI();

} // end setup() -------------------------------------------------------------


void loop() 
{
  // put your main code here, to run repeatedly:
  sensorReading(pTft);

  vTaskDelay(3000 / portTICK_PERIOD_MS);

} // end loop() --------------------------------------------------------------