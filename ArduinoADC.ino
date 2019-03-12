/**
 * Group 3 - Arduino Analog to analog Converter
 *
 * Daniel Copley, Alenn Wright, Corey Cline, Jimmy Banh
 */

// INCLUDES
#include "SARADC.h"
#include "HelperMacros.h"

// PIN DECLARATIONS
uint8_t readInPin = 7;
uint8_t compareOutPin = 9;
uint8_t resolution = 8;
long timeConst = 10000;

// Global Objects
SARADC *AtoD;

void setup()
{
    Serial.begin(115200);
    AtoD = new SARADC(resolution, timeConst, compareOutPin, readInPin);
}

void loop()
{
    Serial.println(AtoD->readVoltage());
    delay(1000);
}
