#include <Arduino.h>
#include <sensorReading.h>

// #include <gfxfont.h>
// #include <Dialog_bold_18.h>

#include <freeFonts.h>
//#include <FreeMono18pt7b.h>

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

  //pTft->setFreeFont(&FreeMono18pt7b);
  //pTft->setFreeFont(&FreeSansBold18pt7b);

  pTft->setTextColor(TFT_WHITE, TFT_BLUE);
  pTft->fillScreen(TFT_BLUE);

  // centre text around x, y position
  //pTft->setTextDatum(TC_DATUM); 

  // create a colored 'field' to display text
  //pTft->fillRect(xPos, yPos, 200, 30, TFT_NAVY);
  // select the font
  // Pass the address of a GFXfont; it's a pointer just as in Adafruit_GFX.h
  // void setFont(const GFXfont *f = NULL);
  pTft->setFreeFont(&FreeSansBold12pt7b);    // not great, but readable ~2858 bytes
  // pTft->setFreeFont(&FreeMono18pt7b);        // not great, but OK
  // pTft->setFreeFont(&FreeSansBold18pt7b);    // NOT working at all ~5175 bytes
  
  // draw text in the selected GFX font
  pTft->drawString("Hello...", xPos, yPos, GFXFF);
  // Get the font height and move ypos down
  yPos += pTft->fontHeight(GFXFF); 
  // ===========================================

  // create a colored 'field' to display text
  //pTft->fillRect(xPos, yPos, 200, 30, TFT_CYAN);
  // select the font
  //pTft->setFreeFont(&FreeSansBold12pt7b);
  // draw text in the selected GFX Free Font
  pTft->drawString("Start my gadget", xPos, yPos, GFXFF);
  // Get the font height and move ypos down
  //ypos += pTft->fontHeight(GFXFF); 

  vTaskDelay(3000 / portTICK_PERIOD_MS);

  //pTft->fillScreen(TFT_BLUE);   // Clear the screen

} // end setup() -------------------------------------------------------------


void loop() 
{
  // xPos centered on the screen width
  xPos = 5; //pTft->width() / 2;
  // yPos just some value away from screen top
  yPos = 50;  

  pTft->setTextColor(TFT_WHITE, TFT_BLUE);
  pTft->fillScreen(TFT_BLUE);

  // draw text in the selected GFX font
  pTft->drawString("Hello...", xPos, yPos, GFXFF);
  // Get the font height and move ypos down
  yPos += pTft->fontHeight(GFXFF); 
  // ===========================================

  // create a colored 'field' to display text
  //pTft->fillRect(xPos, yPos, 200, 30, TFT_CYAN);
  // select the font
  //pTft->setFreeFont(&FreeSansBold12pt7b);
  // draw text in the selected GFX Free Font
  pTft->drawString("Start my gadget", xPos, yPos, GFXFF);
  // Get the font height and move ypos down
  //ypos += pTft->fontHeight(GFXFF); 

  vTaskDelay(6000 / portTICK_PERIOD_MS);

} // end loop() --------------------------------------------------------------
