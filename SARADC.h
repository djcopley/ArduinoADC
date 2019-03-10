//
// Created by djcopley on 3/9/19.
//

#ifndef ARDUINOADC_SARADC_H
#define ARDUINOADC_SARADC_H

#include <Arduino.h>

/**
 *
 */
class SARADC {
public:
    SARADC(uint8_t resolution, long timeConst, uint8_t compareOutPin, uint8_t readInPin);
    float readVoltage();

private:
    uint8_t _lBound, _uBound, _resolution;
    uint8_t *_bitArray;
    const long _delayTime; // Five time constants
    const uint8_t _compareOutPin, _readInPin;

    int findMidpoint(uint8_t lowerBound, uint8_t upperBound);
};


#endif //ARDUINOADC_ADC_H
