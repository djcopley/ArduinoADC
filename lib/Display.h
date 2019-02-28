//
// Created by Daniel Copley on 2019-02-26.
//

#ifndef G3_DISPLAY_H
#define G3_DISPLAY_H

#include <Arduino.h>
#include "HelperMacros.h"

class SevenSegmentDisplay {
public:
    SevenSegmentDisplay(uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t, uint8_t); // Segment pins

private:
    const uint8_t _pin[8]; // TODO... Or just define each segment
};

class Display {
public:
    Display(int, SevenSegmentDisplay *); // Takes number of displays and an address to an array of SevenSegmentDisplays

private:
    const int _numDisplays;
    const SevenSegmentDisplay *_segmentDisplays; // Lowest = leftmost display
};


#endif //G3_DISPLAY_H
