/*
 * SerialHandler.h - Used to handle all serial tasks for Automatic Pill Dispenser
 * Created by Team Licensed to Pill, March 4, 2022
 */

#ifndef SerialHandler_h
#define SerialHandler_h
#include "Arduino.h"
class SerialHandler{
    public:
        // constructor
        SerialHandler();

        // functions
        int* receive_message();
    private:
        // helper functions
        void _flush_buffer();
};

#endif