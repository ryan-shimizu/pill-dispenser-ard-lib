#ifndef LinearRailFlap_h
#define LinearRailFlap_h
#include "Arduino.h"

class LinearRailFlap{
    public:
        // constructor
        LinearRailFlap(uint8_t flap_pin);

        // functions
        void openServo();
        void closeServo();
    private:
        // pinouts
        uint8_t _flap_pin;
};

#endif