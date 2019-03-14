/**
 * Group 3 - Arduino Analog to analog Converter
 *
 * Daniel Copley, Alenn Wright, Corey Cline, Jimmy Banh
 */

// INCLUDES
#include "SARADC.h"
#include "Display.h"
#include "TimerOne.h"
#include "HelperMacros.h"

// PIN DECLARATIONS
uint8_t readInPin = 2;
uint8_t compareOutPin = 3;
uint8_t resolution = 8;
long timeConst = 10000;

uint8_t displays[2][4] = {{4, 5, 6, 7}, {10, 11, 12, 13}};

// Global Objects
SARADC *AtoD;
Display *display;


void setup()
{
    Serial.begin(115200);
    AtoD = new SARADC(resolution, timeConst, compareOutPin, readInPin);
    display = new Display(2, displays);

}

void loop()
{
    Serial.println(AtoD->readVoltage());
    display->displayNum(AtoD->readVoltage());
}
