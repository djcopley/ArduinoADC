//
// Created by Daniel Copley on 2019-02-26.
//

#include "Display.h"

SevenSegmentDisplay::SevenSegmentDisplay(uint8_t pin0, uint8_t pin1, uint8_t pin2, uint8_t pin3, uint8_t pin4,
                                         uint8_t pin5, uint8_t pin6, uint8_t pin7)
{
    _pin[0] = pin0;
    _pin[1] = pin1;
    _pin[2] = pin2;
    _pin[3] = pin3;
    _pin[4] = pin4;
    _pin[5] = pin5;
    _pin[6] = pin6;
    _pin[7] = pin7;
}

Display::Display(int numDisplays, SevenSegmentDisplay *segmentDisplayArray) : _numDisplays(numDisplays),
                                                                              _segmentDisplays(segmentDisplayArray)
{
}

void Display::createNewSegment(SevenSegmentDisplay *)
{
}

