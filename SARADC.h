/**
 * Group 3 - Arduino Analog to analog Converter
 *
 * Daniel Copley, Alenn Wright, Corey Cline, Jimmy Banh
 */

#ifndef ARDUINOADC_SARADC_H
#define ARDUINOADC_SARADC_H

#include <Arduino.h>

/**
 * SARADC class contains information and methods to calculate the voltage.
 */
class SARADC {
public:
    SARADC(uint8_t resolution, long timeConst, uint8_t compareOutPin, uint8_t readInPin); //
    float readVoltage(); // Returns the voltage as a float

private:
    uint8_t _resolution; // Bits of precision
    const long _delayTime; // Five time constants
    const uint8_t _lBound = 0; // Lower bound of PWM
    const uint8_t _uBound = 255; // Upper bound of PWM
    const uint8_t _compareOutPin, _readInPin; // Pin declarations
    const double vFullScale = 5; // Full scale voltage

    int findMidpoint(uint8_t lowerBound, uint8_t upperBound); // Returns the integer midpoint between two bounds
};


#endif //ARDUINOADC_ADC_H
