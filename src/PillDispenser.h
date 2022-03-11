/*
 * PillDispenser.h - Library for Interfacing with Automatic Pill Dispenser Device
 * Created by Team Licensed to Pill, March 4, 2022
 */

#ifndef PillDispenser_h
#define PillDispenser_h
#include "Arduino.h"
#include "LinearRail.h"
#include "Hopper.h"

class PillDispenser{
    public:
        PillDispenser(
        // constructor
            uint8_t rail_step_pin,
            uint8_t rail_dir_pin,
            uint8_t flap_pin,
            uint8_t ir_in,
            uint8_t disk_pin,
            uint8_t actuator_pin
        );

        // functions
        int begin_pill_sort(int message_data[]);

    private:
        // internal components
        bool _days_selected[7];
        uint8_t _dosage_day_selection [7];
        bool _data_populated;

        // physical components
        LinearRail _lr;
        Hopper _hop;

};

#endif
