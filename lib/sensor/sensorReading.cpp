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

    pTft->fillScreen(TFT_BLUE);
    pTft->setTextColor(fGnd, bGnd);
    pTft->setRotation(3);

    // Some message
    //
    pTft->setCursor(5, 20);
    pTft->println("Some message...");

    // Temperature
    //
    // pTft->fillRect(5, 50, 200, 30, bGnd);
    pTft->setCursor( 5, 50);
    // Format tags prototype is %[flags][width][.precision][length]specifier, 
    // https://www.tutorialspoint.com/c_standard_library/c_function_printf.htm
    //
    pTft->printf("Temperature: %6.1f Celcius\n", fTemp);

    // Humidity
    //
    // pTft->fillRect(5, 80, 200, 30, bGnd);
    pTft->setCursor( 5, 80);
    pTft->printf("Humidity...: %6.1f Percent\n", fHumi);

    // Pressure
    //
    // pTft->fillRect(5, 110, 200, 30, bGnd);
    pTft->setCursor( 5, 110);
    pTft->printf("Pressure...: %6.1f hPa\n", fPres);
 
    // Altitude
    //
    // pTft->fillRect(5, 140, 200, 30, bGnd);
    pTft->setCursor( 5, 140);
    pTft->printf("Altitude...: %6.1f meter\n", fAlti);

/*
    Serial.printf("Temperature: %6.1f Celcius\n", fTemp);
    Serial.printf("Altitude...: %6.1f meter\n", fAlti);
    Serial.printf("Humidity...: %6.1f procent\n", fHumi);
    Serial.printf("Pressure...: %6.1f hPa\n", fPres);
*/ 
    //digitalWrite(BUILDIN_LED, LOW);
    Serial.println("------------");

}   // end sensorReading() --------------------------------------------------