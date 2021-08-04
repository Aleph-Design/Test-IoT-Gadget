#include <Arduino.h>
#include <sensorReading.h>

// Include by default ALL available free fonts in directory
// Fonts/GFXFF/...
//
#include <Fonts/GFXFF/gfxfont.h>
// #include <Fonts/GFXFF/FreeSansBold12pt7b.h>  NOT needed!
// #include <Fonts/GFXFF/FreeMono18pt7b.h>      NOT needed!



// pTft is not a real global variable; it's only accessible from within the
// functions in THIS file: NOT in ALL files of the C++ application.
// If you want to make it accessible in all files you'll need to make it
// extern like this: 
// extern TFT_eSPI tft = TFT_eSPI();
//
// To avoid using global variables all over the application we use pointers: 
//
TFT_eSPI *pTft = NULL;    // declare the pointer; no memory allocated yet.


int xPos = 5;
int yPos = 40;


void setup() 
{
  Serial.begin(115200);
  vTaskDelay(500 / portTICK_PERIOD_MS);

  // Create an instance of class TFT_eSPI and assign it's address to the
  // pointer. Now we can pass the pointer around and use methods in the
  // class TFT_eSPI.
  //
  pTft = new TFT_eSPI();
  pTft->init();
  pTft->setRotation(3);

  pTft->setFreeFont(&FreeMonoBold9pt7b);        // not great, but OK ~1672 bytes

  vTaskDelay(1000 / portTICK_PERIOD_MS);

  //pTft->fillScreen(TFT_BLUE);   // Clear the screen

} // end setup() -------------------------------------------------------------


void loop() 
{
  sensorReading(pTft);

  vTaskDelay(6000 / portTICK_PERIOD_MS);

} // end loop() --------------------------------------------------------------
