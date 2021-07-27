#include <Arduino.h>
#include <settings.h>
#include <sensorReading.h>


void sensorReading(TFT_eSPI *pTft)
{
    float fTemp = 24.3;
    float fHumi = 57.8;
    float fPres = SEALEVELPRESSURE_HPA;
    float fAlti = -3.57;

    //pTft->printf

    // Temperature
    //
    Serial.printf("Temperature: %f\n", fTemp);

    // Humidity
    //
    Serial.printf("Humidity...: %f\n", fHumi);

    // Pressure
    //
    Serial.printf("Pressure...: %f\n", fPres);

    // Altitude
    //
    Serial.printf("Altitude...: %f\n", fAlti);
 
    digitalWrite(BUILDIN_LED, LOW);
    Serial.println("------------");

}   // end sensorReading() --------------------------------------------------