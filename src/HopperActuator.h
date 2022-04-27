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
        void set_level(uint8_t level);
        void reset_arm();

        uint8_t curr_level;
    private:
        // functions 
        void _move_stepper(long long int steps, bool dir);
        
        // pinouts
        uint8_t _actuator_pin;
        uint8_t _actuator_dir_pin;

        // data members
        
};

#endif