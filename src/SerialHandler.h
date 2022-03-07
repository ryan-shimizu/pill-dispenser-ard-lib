/*
 * SerialHandler.h - Used to handle all serial tasks for Automatic Pill Dispenser
 * Created by Team Licensed to Pill, March 4, 2022
 */

#ifndef SerialHandler_h
#define SerialHandler_h
#include "Arduino.h"

#define DEBUG Serial
#define NEXTION Serial1

class SerialHandler{
    public:
        SerialHandler();
        int* receive_message();
    private:
        int _buffer [8];        // each message is 8 bytes long
        void _flush_buffer();
};

#endif