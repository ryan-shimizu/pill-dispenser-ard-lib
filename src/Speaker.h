/*
 * Speaker.h - Speaker interface
 * Header file for Speaker module
 * Created by Team Licensed to Pill, March 4, 2022
 */

#ifndef Speaker_h
#define Speaker_h
//#include "Arduino.h"

class Speaker{
    public:
        // constructor
        Speaker(uint8_t speaker_pin);

        // functions
        void play_tune();

    private:
        // pinouts
        uint8_t _speaker_pin;
};

#endif
