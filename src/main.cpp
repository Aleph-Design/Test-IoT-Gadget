#include <Arduino.h>
#include <sensorReading.h>

#define AA_FONT_SMALL "NotoSansBold-15"
#define AA_FONT_LARGE "NotoSansBold-36"

//#define LIST_FILES  0


// pTft is not a real global variable; it's only accessible from within the
// functions in THIS file: NOT in ALL files of the C++ application.
// If you want to make it accessible in all files you'll need to make it
// extern like this: 
// extern TFT_eSPI tft = TFT_eSPI();
//
// To avoid using global variables all over the application we use pointers: 
//
TFT_eSPI *pTft = NULL;    // declare the pointer; no memory allocated yet.

// Proto types
//
void listDir(fs::FS &fs, const char * dirname, uint8_t levels);
void rainbow_fill();
// Callback function to provide the pixel color at x,y
//
uint16_t pixelColor(uint16_t x, uint16_t y) { return pTft->readPixel(x, y); }


int xPos = 5;
int yPos = 40;


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


  // ESP32 will crash if any of the fonts are missing
  //
  #if defined(LIST_FILES)
    // List the files so you can see what is in the SPIFFS
    //
    listDir(SPIFFS, "/", true);
  #else
    if (!SPIFFS.exists("/NotoSansBold-15.vlw"))
    {
      Serial.println("\r\nFont file '/NotoSansBold-15.vlw' missing in SPIFFS, did you upload it?\n");
      while(1) yield();  
    }
    if (!SPIFFS.exists("/NotoSansBold-36.vlw"))
    {
      Serial.println("\r\nFont file '/NotoSansBold-36.vlw' missing in SPIFFS, did you upload it?\n");
      while(1) yield();
    }

    Serial.println("\r\nSPIFFS Font files found OK.\n\n");
  #endif // LIST_FILES

  // Create an instance of class TFT_eSPI and assign it's address to the
  // pointer. Now we can pass the pointer around and use methods in the
  // class TFT_eSPI.
  //
  pTft = new TFT_eSPI();
  pTft->init();

  pTft->setRotation(3);
  // The callback is only used during font rendering
  //
  pTft->setCallback(pixelColor);  

  vTaskDelay(1000 / portTICK_PERIOD_MS);

  //pTft->fillScreen(TFT_BLUE);   // Clear the screen

} // end setup() -------------------------------------------------------------


void loop() 
{
  rainbow_fill(); // Fill the screen with rainbow colours

  // Select a font size comensurate with screen size
  // loadFont() comes from Smooth_font.cpp/h
  //
  // if (pTft->width() >= 320)
  //   pTft->loadFont(AA_FONT_LARGE);
  // else
    pTft->loadFont(AA_FONT_SMALL);

  pTft->setTextColor(TFT_BLACK, TFT_WHITE); // Background color is ignored if callback is set
  pTft->setCursor(0, 10); // Set cursor at top left of screen

  uint32_t t = millis();
  pTft->println(" Ode to a small\n lump of green\n putty I found\n in my armpit\n one midsummer\n morning ");
  Serial.println(t = millis()-t);

  pTft->unloadFont(); // Remove the font to recover memory used

  //sensorReading(pTft);

  vTaskDelay(6000 / portTICK_PERIOD_MS);

} // end loop() --------------------------------------------------------------



/* 
* -------------------------------------------------------------------------
* List files in ESP32 SPIFFS memory
* -------------------------------------------------------------------------
*/
void listDir(fs::FS &fs, const char * dirname, uint8_t levels) 
{
  Serial.printf("Listing directory: %s\n", dirname);

  fs::File root = fs.open(dirname);
  if (!root) 
  {
    Serial.println("Failed to open directory");
    return;
  }
  if (!root.isDirectory()) 
  {
    Serial.println("Not a directory");
    return;
  }

  fs::File file = root.openNextFile();
  while (file) 
  {
    if (file.isDirectory()) 
    {
      Serial.print("DIR : ");
      String fileName = file.name();
      Serial.print(fileName);
      if (levels) listDir(fs, file.name(), levels - 1);
    } else {
      String fileName = file.name();
      Serial.print("  " + fileName);
      int spaces = 32 - fileName.length(); // Tabulate nicely
      if (spaces < 1) spaces = 1;
      while (spaces--) Serial.print(" ");
      String fileSize = (String) file.size();
      spaces = 8 - fileSize.length(); // Tabulate nicely
      if (spaces < 1) spaces = 1;
      while (spaces--) Serial.print(" ");
      Serial.println(fileSize + " bytes");
    }

    file = root.openNextFile();

  } // while()

} // end listdir() -----------------------------------------------------------



/*
* #########################################################################
* Fill screen with a rainbow pattern
* #########################################################################
*/
byte red    = 31;
byte green  = 0;
byte blue   = 0;
byte state  = 0;
unsigned int colour = red << 11; // Colour order is RGB 5+6+5 bits each

void rainbow_fill()
{

} // end rainbow_fill() ------------------------------------------------------