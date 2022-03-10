/*
 * LinearRail.h - Used to manipulate Linear Rail motor
 * Created by Team Licensed to Pill, March 4, 2022
 */

#ifndef LinearRail_h
#define LinearRail_h
#include "Arduino.h"
#include "LinearRailFlap.h"

class LinearRail{
    public:
        // constructor
        LinearRail(uint8_t flap_pin, uint8_t rail_dir_pin, uint8_t rail_step_pin);

        // functions
        void dispense_by_day(uint8_t day);
	// the fuctions to grab pins ???


    private:
        // helper functions
        void _move_stepper(int movedSteps, bool direction);
        void _drop_pill();

        // pinouts
        uint8_t _flap_pin;    //might not need this if using pin grabbing function
        uint8_t _rail_step_pin;
	uint8_t _rail_dir_pin;
	

        // physical components
        LinearRailFlap _lr_flap;
};

#endif