/*
 * Hopper.h - Used to manipulate hopper portion of the device
 * Encapsulates HopperActuator, HopperDisk, and IRSensor.
 * Created by Team Licensed to Pill, March 4, 2022
 */

#ifndef Hopper_h
#define Hopper_h

#include "Arduino.h"
#include "HopperActuator.h"
#include "HopperDisk.h"
#include "IRSensor.h"

class Hopper{
    public:
        // constructor
        Hopper(uint8_t disk_pin, uint8_t actuator_pin, uint8_t ir_pin);

        // functions
        void transfer_pills(uint8_t num);
        void set_funnel_size(uint8_t steps);
    private:
        // components
        HopperActuator _ha;
        HopperDisk _hd;
        IRSensor _ir;
};

#endif