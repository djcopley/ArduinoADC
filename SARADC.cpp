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
                                                                                               _delayTime(5 * timeConst) {

    pinMode(_compareOutPin, OUTPUT);
    pinMode(_readInPin, INPUT);

    _lBound = 0;
    _uBound = 255;

    if (resolution == 0) {
        resolution = 8;
    } else {
        _resolution = resolution;
    }
    _bitArray = new byte[_resolution];
}

/**
 *
 * @param lowerBound
 * @param upperBound
 * @return
 */
int SARADC::findMidpoint(uint8_t lowerBound, uint8_t upperBound) {
    return ((upperBound - lowerBound) / 2) + upperBound;
}

/**
 *
 * @return
 */
float SARADC::readVoltage() {

    double voltage = 0;

    for (int i; i < _resolution; i++) {
        byte mid = findMidpoint(_lBound, _uBound);
        analogWrite(_compareOutPin, mid);
        delayMicroseconds(_delayTime);
        _bitArray[i] = digitalRead(_delayTime);
        if (_bitArray[i]) {
            _lBound = mid;
            voltage += (2.5 / pow(2, i));
        } else {
            _uBound = mid;
        }
    }
    return voltage;
}