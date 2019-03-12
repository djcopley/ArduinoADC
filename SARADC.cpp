//
// Created by djcopley on 3/9/19.
//

#include "SARADC.h"

/**
 *
 * @param resolution
 * @param compareOutPin
 * @param readInPin
 * @param timeConst time for RC filter to settle in microseconds
 */
SARADC::SARADC(uint8_t resolution, long timeConst, uint8_t compareOutPin, uint8_t readInPin) : _resolution(resolution),
                                                                                               _compareOutPin(compareOutPin),
                                                                                               _readInPin(readInPin),
                                                                                               _delayTime(6 * timeConst)
{
    pinMode(_compareOutPin, OUTPUT);
    pinMode(_readInPin, INPUT);

    if (resolution == 0) {
        resolution = 8;
    } else {
        _resolution = resolution;
    }
}

/**
 *
 * @param lowerBound
 * @param upperBound
 * @return
 */
int SARADC::findMidpoint(uint8_t lowerBound, uint8_t upperBound)
{
    return ((upperBound - lowerBound) / 2) + lowerBound;
}

/**
 *
 * @return
 */
float SARADC::readVoltage()
{
    double voltage = 0;
    uint8_t tmpLBound = _lBound;
    uint8_t tmpUBound = _uBound;

    for (int i = 0; i < _resolution; i++) {
        uint8_t mid = findMidpoint(tmpLBound, tmpUBound);
        analogWrite(_compareOutPin, mid);
        delayMicroseconds(_delayTime);
        bool state = !digitalRead(_readInPin);

        if (state) {
            tmpLBound = mid;
            voltage += vFullScale / pow(2, i + 1); // (vFullScale / _resolution);
        } else {
            tmpUBound = mid;
        }
    }
    return voltage;
}