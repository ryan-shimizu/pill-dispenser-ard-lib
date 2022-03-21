/*
 * HopperActuator.h - Actuator Interface
 * Specifically manipulates actuator device on Hopper
 * Created by Team Licensed to Pill, March 4, 2022
 */

#ifndef HopperActuator_h
#define HopperActuator_h
#include "Arduino.h"

class HopperActuator{
    public:
        // constructor
        HopperActuator(uint8_t actuator_pin, uint8_t actuator_dir_pin);

        // functions
        // TODO: What functions do we need??
    private:
        // pinouts
        uint8_t _actuator_pin;
        uint8_t _actuator_dir_pin;
};

#endif