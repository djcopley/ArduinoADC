/**
 * Group 3 - Arduino Analog to analog Converter
 *
 * Daniel Copley, Alenn Wright, Corey Cline, Jimmy Banh
 */

#ifndef ARDUINOADC_DISPLAY_H
#define ARDUINOADC_DISPLAY_H

#include <Arduino.h>
#include <math.h>

class Display {
public:
    Display(uint8_t numDisplays, uint8_t displays[][4]);
    void displayNum(float value);

private:
    // Pin conversions for each number
    const uint8_t NUMBER2PINOUT[16][4] =
            {
                    {LOW,  LOW,  LOW,  LOW},
                    {LOW,  LOW,  LOW,  HIGH},
                    {LOW,  LOW,  HIGH, LOW},
                    {LOW,  LOW,  HIGH, HIGH},
                    {LOW,  HIGH, LOW,  LOW},
                    {LOW,  HIGH, LOW,  HIGH},
                    {LOW,  HIGH, HIGH, LOW},
                    {LOW,  HIGH, HIGH, HIGH},
                    {HIGH, LOW,  LOW,  LOW},
                    {HIGH, LOW,  LOW,  HIGH},
                    {HIGH, LOW,  HIGH, LOW},
                    {HIGH, LOW,  HIGH, HIGH},
                    {HIGH, HIGH, LOW,  LOW},
                    {HIGH, HIGH, LOW,  HIGH},
                    {HIGH, HIGH, HIGH, LOW},
                    {HIGH, HIGH, HIGH, HIGH}
            };
    uint8_t _numDisplays, _displays[2][4]; // [display][pins]
    const uint8_t _pinsPerDisplay = 4; // Number of pins per display
    void writeSevenSegment(uint8_t display, uint8_t number); // Method writes to an individual display
};


#endif //ARDUINOADC_DISPLAY_H
