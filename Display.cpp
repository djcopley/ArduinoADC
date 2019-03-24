
/*
 * Group 3 - Arduino Analog to analog Converter
 *
 * Daniel Copley, Alenn Wright, Corey Cline, Jimmy Banh
 */

#include "Display.h"

/**
 * Display class Constructor.
 *
 * @param numDisplays number of seven segment displays
 * @param displays 2 dimensional array of [displays][pins]
 */
Display::Display(uint8_t numDisplays, uint8_t displays[][4])
{
    _numDisplays = numDisplays;

    for (int display = 0; display < numDisplays; display++) {
        for (int pin = 0; pin < _pinsPerDisplay; pin++) {
            _displays[display][pin] = displays[display][pin];
            pinMode(_displays[display][pin], OUTPUT);
        }
    }
}

/**
 * Takes a float value and displays it on the seven segment displays.
 *
 * @param value to write to displays
 */
void Display::displayNum(float value)
{
    double integer, fraction;
    fraction = modf(value, &integer) * 10; // split the decimal and the integer value

    int decimal = (uint8_t) round(fraction);

    if (decimal == 10) {
        integer++;
        decimal = 0;
    }

    writeSevenSegment(0, (uint8_t) integer);
    writeSevenSegment(1, decimal);
}

/**
 * Takes a value and writes it to a specific segment
 *
 * @param display the display number (from _displays array)
 * @param number integer value to write to display
 */
void Display::writeSevenSegment(uint8_t display, uint8_t number)
{
    for (int pin = 0; pin < _pinsPerDisplay; pin++) {
        digitalWrite(_displays[display][pin], NUMBER2PINOUT[number][pin]);
    }
}