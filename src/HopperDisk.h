/*
 * HopperDisk.h - Actuator Interface
 * Specifically manipulates disk portion of hopper
 * Created by Team Licensed to Pill, March 4, 2022
 */

#ifndef HopperDisk_h
#define HopperDisk_h
#include "Arduino.h"
#include "Stepper.h"

class HopperDisk{
    public:
        // constructor
        HopperDisk(uint8_t disk_pin, uint8_t disk_dir_pin);

        // functions
        void rotate_disk(int duty_cycle, bool dir);
    private:
        // pinouts
        uint8_t _disk_pin;
        uint8_t _disk_dir_pin;
        // Stepper _disk;
};

#endif