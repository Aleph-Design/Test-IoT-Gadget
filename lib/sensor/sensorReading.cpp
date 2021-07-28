#include <Arduino.h>
#include <settings.h>
#include <sensorReading.h>


void sensorReading(TFT_eSPI *pTft)
{
    float fTemp = 24.3;
    float fHumi = 57.8;
    float fPres = SEALEVELPRESSURE_HPA;
    float fAlti = -3.57;

    uint16_t fGnd = TFT_WHITE;
    uint16_t bGnd = TFT_BLUE;

    pTft->setTextColor(fGnd, bGnd);
    // fonts are accessible as long as they are stored inside the 'data' 
    // directory and contained in a *vlw file format.
    //
    //pTft->loadFont()
    pTft->setRotation(3);
    pTft->setCursor(5, 5);
    pTft->println("Right now...");

    // Temperature
    //
    pTft->fillRect(5, 20, 200, 30, bGnd);
    pTft->setCursor( 5, 20);
    // Format tags prototype is %[flags][width][.precision][length]specifier, 
    // https://www.tutorialspoint.com/c_standard_library/c_function_printf.htm
    //
    pTft->printf("Temperature: %6.1f Celcius\n", fTemp);
    Serial.printf("Temperature: %6.1f Celcius\n", fTemp);

    // Humidity
    //
    pTft->fillRect(5, 60, 200, 30, bGnd);
    pTft->setCursor( 5, 60);
    pTft->printf("Humidity...: %6.1f Percent\n", fHumi);
    Serial.printf("Humidity...: %6.1f procent\n", fHumi);

    // Pressure
    //
    pTft->fillRect(5, 100, 200, 30, bGnd);
    pTft->setCursor( 5, 100);
    pTft->printf("Pressure...: %6.1f hPa\n", fPres);
    Serial.printf("Pressure...: %6.1f hPa\n", fPres);

    // Altitude
    //
    pTft->fillRect(5, 140, 200, 30, bGnd);
    pTft->setCursor( 5, 140);
    pTft->printf("Altitude...: %6.1f meter\n", fAlti);
    Serial.printf("Altitude...: %6.1f meter\n", fAlti);
 
    digitalWrite(BUILDIN_LED, LOW);
    Serial.println("------------");

}   // end sensorReading() --------------------------------------------------