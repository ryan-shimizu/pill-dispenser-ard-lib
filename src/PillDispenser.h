/*
 * PillDispenser.h - Library for Interfacing with Automatic Pill Dispenser Device
 * Created by Team Licensed to Pill, March 4, 2022
 */

#ifndef PillDispenser_h
#define PillDispenser_h
#include "Arduino.h"
#include "LinearRail.h"
#include "Hopper.h"
#include "Speaker.h"

class PillDispenser{
    public:
        PillDispenser(
        // constructor
            uint8_t rail_step_pin,
            uint8_t rail_dir_pin,
            uint8_t flap_pin,
            uint8_t ir_pin,
            uint8_t disk_pin,
            uint8_t disk_dir_pin,
            uint8_t actuator_pin,
            uint8_t actuator_dir_pin,
            uint8_t speaker_pin,
            uint8_t rail_limit_switch,
            uint8_t actuator_limit_switch
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
        Speaker _speaker;

};

#endif
