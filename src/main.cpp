#include <Arduino.h>
#include <sensorReading.h>


// pTft is not a real global variable; it's only accessible from within the
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

  // Check for SPIFFS
  //
  if (!SPIFFS.begin()) 
  {
    Serial.println("SPIFFS initialisation failed!");
    while (1) yield(); // Stay here twiddling thumbs waiting
  }
  Serial.println("\r\nSPIFFS available!\n");


  // Create an instance of class TFT_eSPI and assign it's address to the
  // pointer. Now we can pass the pointer around and use methods in the
  // class TFT_eSPI.
  //
  pTft = new TFT_eSPI();
  pTft->init();
  pTft->setRotation(3);

  // Draw a border and fill it
  //
	pTft->fillRect(1, 1, 318, 43, TFT_RED);
	pTft->drawRect(0, 0, 320, 45, TFT_YELLOW);

  vTaskDelay(1000 / portTICK_PERIOD_MS);

  //pTft->fillScreen(TFT_BLUE);   // Clear the screen

} // end setup() -------------------------------------------------------------


void loop() 
{
  // Fill the screen
  pTft->fillScreen(TFT_NAVY);

	// Draw a border and fill it
  //
	pTft->fillRect(1, 1, 318, 43, TFT_RED);
	pTft->drawRect(0, 0, 320, 45, TFT_YELLOW);

  // Message "Font file ... not found" comes from TFT_eSPI.cpp
  //
  // pTft->loadFont("NotoSansBold-15");  
  // pTft->loadFont("NotoSansBold-15.vlw"); 
  pTft->loadFont("data/NotoSansBold-15.vlw");
  // // pTft->setTextSize(1);  // Blocks the TFT-screen from working!
  pTft->setCursor(15, 30);
  // // Set text color and background
  pTft->setTextColor(TFT_YELLOW, TFT_RED);
  pTft->println(">> ESP32 WEB RADIO <<");

  // vTaskDelay(6000 / portTICK_PERIOD_MS);

  sensorReading(pTft);

  vTaskDelay(6000 / portTICK_PERIOD_MS);

} // end loop() --------------------------------------------------------------
