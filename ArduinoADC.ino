/**
 * Group 3 - Arduino Analog to analog Converter
 *
 * Daniel Copley, Alenn Wright, Corey Cline, Jimmy Banh
 */

// INCLUDES
#include "SARADC.h"
#include "Display.h"
#include "TimerOne.h"
#include <avr/sleep.h>
#include "HelperMacros.h"

// Prototypes
void sleep();
void wake();

// PIN DECLARATIONS
const uint8_t interruptPin = 2;
const uint8_t readInPin = 8;
const uint8_t compareOutPin = 3;
const uint8_t resolution = 8;
const long timeConst = 10000;
const uint8_t displays[2][4] = {{4,  5,  6,  7},
                                {10, 11, 12, 13}};

// Global Variables
float newVoltage, oldVoltage;
unsigned long timeoutTimer = millis();
unsigned long timeoutPeriod = 10000; // 10 seconds

// Global Objects
SARADC *AtoD;
Display *display;


void setup()
{
    // Initialize objects
    Serial.begin(115200);
    AtoD = new SARADC(resolution, timeConst, compareOutPin, readInPin);
    display = new Display(2, displays);

    // Configure interrupts
    interrupts();
    attachInterrupt(digitalPinToInterrupt(interruptPin), wake, RISING);

}

void loop()
{
    newVoltage = AtoD->readVoltage();

    Serial.println(newVoltage);

    if (newVoltage != oldVoltage) {
        timeoutTimer = millis();
    }

    if (millis() - timeoutTimer > timeoutPeriod) {
        sleep();
    }

    display->displayNum(newVoltage);
    oldVoltage = newVoltage;
}

void wake()
{
    sleep_disable();
}

void sleep()
{
    // Enable LPM
    set_sleep_mode(SLEEP_MODE_PWR_DOWN);
    sleep_enable();
    attachInterrupt(digitalPinToInterrupt(2), wake, RISING);
    sleep_mode();
    detachInterrupt(digitalPinToInterrupt(2));
}