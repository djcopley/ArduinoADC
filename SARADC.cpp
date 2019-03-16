/**
 * Group 3 - Arduino Analog to analog Converter
 *
 * Daniel Copley, Alenn Wright, Corey Cline, Jimmy Banh
 */

#include "SARADC.h"

/**
 * SARADC class class constructor.
 *
 * @param resolution selectable ADC precision
 * @param compareOutPin output pin #
 * @param readInPin input pin #
 * @param timeConst time for RC filter to settle in microseconds
 */
SARADC::SARADC(uint8_t resolution, long timeConst, uint8_t compareOutPin, uint8_t readInPin) : _resolution(resolution),
                                                                                               _compareOutPin(compareOutPin),
                                                                                               _readInPin(readInPin),
                                                                                               _delayTime(6 * timeConst)
{
    // Set pin modes
    pinMode(_compareOutPin, OUTPUT);
    pinMode(_readInPin, INPUT_PULLUP);

    // If resolution is 0, set to max
    if (resolution == 0) {
        resolution = 8;
    } else {
        _resolution = resolution;
    }
}

/**
 * Method finds the point between two bounds.
 *
 * @param lowerBound of midpoint
 * @param upperBound of midpoint
 * @return midpoint
 */
int SARADC::findMidpoint(uint8_t lowerBound, uint8_t upperBound)
{
    return ((upperBound - lowerBound) / 2) + lowerBound;
}

/**
 * Returns the voltage as a float.
 *
 * @return the voltage as a float
 */
float SARADC::readVoltage()
{
    float voltage = 0;
    uint8_t tmpLBound = _lBound;
    uint8_t tmpUBound = _uBound;

    for (int i = 0; i < _resolution; i++) {
        uint8_t mid = findMidpoint(tmpLBound, tmpUBound);
        analogWrite(_compareOutPin, mid);
        delayMicroseconds(_delayTime); // Wait for the RC filter to stabilize
        bool state = !digitalRead(_readInPin);

        if (state) {
            tmpLBound = mid; // Set lower bound to current midpoint
            voltage += vFullScale / pow(2, i + 1); // (vFullScale / 2^i);
        } else {
            tmpUBound = mid; // Set upper bound to current midpoint
        }
    }
    return voltage;
}