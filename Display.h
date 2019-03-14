//
// Created by djcopley on 3/12/19.
//

#ifndef ARDUINOADC_DISPLAY_H
#define ARDUINOADC_DISPLAY_H

#include <Arduino.h>
#include <math.h>

class Display {
public:
    Display(uint8_t numDisplays, uint8_t displays[][4]);
    void displayNum(float value);

private:
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
    const uint8_t _pinsPerDisplay = 4;
    void writeSevenSegment(uint8_t display, uint8_t number);
};


#endif //ARDUINOADC_DISPLAY_H
