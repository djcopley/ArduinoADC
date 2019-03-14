//
// Created by djcopley on 3/12/19.
//

#include "Display.h"

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

void Display::displayNum(float value)
{
    double integer, fraction;
    fraction = modf(value, &integer) * 10;

    Serial.println((uint8_t) round(fraction));

    writeSevenSegment(0, (uint8_t) integer);
    writeSevenSegment(1, (uint8_t) round(fraction));
}

void Display::writeSevenSegment(uint8_t display, uint8_t number)
{
    for (int pin = 0; pin < _pinsPerDisplay; pin++) {
        digitalWrite(_displays[display][pin], NUMBER2PINOUT[number][pin]);
    }
}