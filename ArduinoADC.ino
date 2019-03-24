/*
 * Group 3 - Arduino Analog to Digital Converter
 *
 * Daniel Copley, Alenn Wright, Corey Cline, Jimmy Banh
 */

// INCLUDES
#include "SARADC.h"
#include "Display.h"
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
    // Current Voltage
    newVoltage = AtoD->readVoltage();

    // Print reading to serial port
    Serial.println(newVoltage);
  
    // If the voltage has changed, refresh the timer
    if (newVoltage != oldVoltage) {
        timeoutTimer = millis();
    }

    // If the program times out, enter sleep mode
    if (millis() - timeoutTimer > timeoutPeriod) {
        sleep();
    }

    // Update the display voltage
    display->displayNum(newVoltage);
    oldVoltage = newVoltage;
}

/**
 * Wake function wakes the processor from sleep
 */
void wake()
{
    sleep_disable();
}

/**
 * Sleep function puts the processor to sleep
 */
void sleep()
{
    // Enable LPM
    set_sleep_mode(SLEEP_MODE_PWR_DOWN);
    sleep_enable();
    attachInterrupt(digitalPinToInterrupt(2), wake, RISING);
    sleep_mode();
    detachInterrupt(digitalPinToInterrupt(2));
}