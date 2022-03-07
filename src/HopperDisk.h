/*
 * HopperDisk.h - Actuator Interface
 * Specifically manipulates disk portion of hopper
 * Created by Team Licensed to Pill, March 4, 2022
 */

#ifndef HopperDisk_h
#define HopperDisk_h
#include "Arduino.h"

class HopperDisk{
    public:
        // constructor
        HopperDisk(uint8_t disk_pin);

        // functions
        void rotate_disk();
    private:
        // pinouts
        uint8_t _disk_pin;
};

#endif