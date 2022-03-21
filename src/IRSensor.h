/*
 * IRSensor.h - IR Sensor interface library
 * Created by Team Licensed to Pill, March 4, 2022
 */

#ifndef IRSensor_h
#define IRSensor_h
#include "Arduino.h"

class IRSensor{
    public:
        // constructor
        IRSensor(uint8_t ir_pin);

        // functions
        bool check_pill_count(uint8_t count);
        void clear_count();
    private:
        // pinouts
        uint8_t _ir_pin;
        
        // internal components
        //volatile uint8_t _pill_count;       // may be changed by ISR?
};

#endif