/*
 * LinearRail.h - Used to manipulate Linear Rail motor
 * Created by Team Licensed to Pill, March 4, 2022
 */

#ifndef LinearRail_h
#define LinearRail_h
#include "Arduino.h"
#include "LinearRailFlap.h"
#include "Stepper.h"

class LinearRail{
    public:
        // constructor
        LinearRail(uint8_t flap_pin, uint8_t rail_dir_pin, uint8_t rail_step_pin, uint8_t rail_limit_switch);

        // functions
        void dispense_by_day(uint8_t day);

    private:
        // helper functions
        void _move_stepper(long long unsigned int movedSteps, bool direction);
        void _drop_pill();
        void _move_stepper_pwm();

        // pinouts
        uint8_t _flap_pin;    //might not need this if using pin grabbing function
        uint8_t _rail_step_pin;
	    uint8_t _rail_dir_pin;
        uint8_t _rail_limit_switch;
	

        // physical components
        LinearRailFlap _lr_flap;
        //Stepper _rail;
};

#endif