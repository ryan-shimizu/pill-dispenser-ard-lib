/*
 * PillDispenser.cpp - Library for Interfacing with Automatic Pill Dispenser Device
 * Created by Team Licensed to Pill, March 4, 2022
 */

#include "PillDispenser.h"
#define NUM_DAYS 7

PillDispenser::PillDispenser(
            uint8_t rail_pin,
            uint8_t flap_pin,
            uint8_t ir_pin,
            uint8_t disk_pin,
            uint8_t actuator_pin)
            : _hop(
                disk_pin=disk_pin,
                actuator_pin=actuator_pin,
                ir_pin=ir_pin),
              _lr(
                flap_pin=flap_pin,
                rail_pin=rail_pin
              )
{
    // fill values to 0
    for(uint8_t idx; idx<NUM_DAYS; idx++){
        this->_days_selected[idx] = false;
        this->_dosage_day_selection[idx] = 0;
    }
    this->_data_populated = false;
}

int PillDispenser::begin_pill_sort(){
    /*
     * Function that begins the pill sorting process.
     * Contains all logic for manipulating peripherals
     *  Args:
     *      None
     *  Returns:
     *      errorCode(int):         Error codes //TODO: define
     */

    // TODO: Implement
}

void PillDispenser::parse_serial_message(int message_data[]){
    /*
     * Function that parses incoming serial message
     * and sets internal variables to reflect the data.
     *  Args:
     *      message_data(int[]):    8-element array containing all bytes received
     *                              from SerialHandler
     *  Returns:
     *      errorCode(int):         Error codes //TODO: define
     */
    // TODO: Implement (Ryan)
    
}