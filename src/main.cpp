#include <Arduino.h>
#include <sensorReading.h>

#include <SPIFFS.h>
#include <FS.h>

// pTft is not a real global variable; it's only accessible from within the
// functions in THIS file: NOT in ALL files of the C++ application.
// If you want to make it accessible in all files you'll need to make it
// extern like this: 
// extern TFT_eSPI tft = TFT_eSPI();
//
// To avoid using global variables all over the application we use pointers: 
//
TFT_eSPI *pTft = NULL;    // declare the pointer; no memory allocated yet.


void listDir();


void setup() 
{
  Serial.begin(115200);
  vTaskDelay(500 / portTICK_PERIOD_MS);

  if (!SPIFFS.begin(true))
  {
    Serial.printf("\nSPIFFS initialization failed!\n");
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }

  Serial.printf("\nSPIFFS initialization succesfull\n");
  Serial.printf("================================\n\n");

  // Check whether the font files are on the ESP32
  //
  listDir();

  // Create an instance of class TFT_eSPI and assign it's address to the
  // pointer. Now we can pass the pointer around and use methods in the
  // class TFT_eSPI.
  //
  pTft = new TFT_eSPI();
  pTft->init();
  pTft->setRotation(3);

  //pTft->loadFont("SansSerif36", true);
  //pTft->loadFont("NotoSansBold-36", true);
  //Serial.printf("\nfontsloaded: %d\n\n", pTft->fontsLoaded());

  pTft->setTextColor(TFT_WHITE, TFT_BLUE);
  pTft->fillScreen(TFT_BLUE);

  pTft->fillRect(5, 5, 200, 30, TFT_BLUE);
  pTft->setCursor( 5, 5);
  pTft->println("Hello...");

  pTft->fillRect(5, 35, 200, 30, TFT_BLUE);
  pTft->setCursor( 5, 35);
  pTft->println("Start my gadget");

  vTaskDelay(3000 / portTICK_PERIOD_MS);

  //pTft->fillScreen(TFT_BLUE);   // Clear the screen

} // end setup() -------------------------------------------------------------


void loop() 
{
  // put your main code here, to run repeatedly:
  //sensorReading(pTft);

  //vTaskDelay(3000 / portTICK_PERIOD_MS);

} // end loop() --------------------------------------------------------------



void listDir()
{
  Serial.printf("---Dir: /:\n");
  
  fs::File root = SPIFFS.open("/", "r");
  fs::File file = root.openNextFile("r");

  while(file)
  { 
      Serial.print("FILE: ");
      Serial.println(file.name());
      file = root.openNextFile();

      vTaskDelay(500 / portTICK_PERIOD_MS);
  }
} // end listDir() -----------------------------------------------------------
