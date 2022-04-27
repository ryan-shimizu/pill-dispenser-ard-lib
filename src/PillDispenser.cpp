/*
 * PillDispenser.cpp - Library for Interfacing with Automatic Pill Dispenser Device
 * Created by Team Licensed to Pill, March 4, 2022
 */

#include "PillDispenser.h"
#define NUM_DAYS 7
#define DEBUG Serial

PillDispenser::PillDispenser(
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
            uint8_t actuator_limit_switch)
            : _hop(
                disk_pin=disk_pin,
                disk_dir_pin=disk_dir_pin,
                actuator_pin=actuator_pin,
                actuator_dir_pin=actuator_dir_pin,
                ir_pin=ir_pin),
              _lr(
                flap_pin=flap_pin,
                rail_dir_pin=rail_dir_pin,
                rail_step_pin=rail_step_pin,
                rail_limit_switch=rail_limit_switch
              ),
              _speaker(
                  speaker_pin=speaker_pin
              ),
              _sh()
{
    // fill values to 0
    for(uint8_t idx; idx<NUM_DAYS; idx++){
        this->_days_selected[idx] = false;
        this->_dosage_day_selection[idx] = 0;
    }
    this->_data_populated = false;
}

int PillDispenser::begin_pill_sort(int message_data[]){
    /*
     * Function that begins the pill sorting process.
     * Contains all logic for manipulating peripherals
     *  Args:
     *      messageData(int*):      8-element int array containing all 8 bytes
     *                              received from SerialHandler.
     *  Returns:
     *      errorCode(int):         Error codes
     *          1: Header byte invalid
     */

    
    // verify that header is as expected


    // begin parsing day select data
    int day_select_byte = message_data[2]>>1;   // dont care about last bit
    bool day_select_data[NUM_DAYS];
    for(uint8_t idx=0; idx<NUM_DAYS; idx++){
        day_select_data[6-idx] = (((day_select_byte>>idx) & 0b1) == 0b1) ? true : false;
    }

    // debug shit
    for(uint8_t idx=0; idx<NUM_DAYS; idx++){
        if(day_select_data[idx]){
            String debug = "PillDispenser.cpp: Index " + String(idx) + " day select parsed true.";
            DEBUG.println(debug);
        }
        else{
            String debug = "PillDispenser.cpp: Index " + String(idx) + " day select parsed false.";
            DEBUG.println(debug); 
        }
    }

    String dayReference[7] = {
        "Sunday",
        "Monday",
        "Tuesday",
        "Wednesday",
        "Thursday",
        "Friday",
        "Saturday"
    };

    // begin parsing dosage select data
    int dos_select_byte1 = message_data[3];
    int dos_select_byte2 = message_data[4];

    uint8_t dos_select1[4];
    uint8_t dos_select2[3];

    //dos_select_byte1
    for(uint8_t idx=0; idx<4; idx++){
        // looping 4 times bc dos_select_byte1 has data for 4 days
        int temp = dos_select_byte1>>(idx*2) & 0b11;
        uint8_t rolling_idx = 3 - idx;
        dos_select1[rolling_idx] = uint8_t(temp+1);
    }

    // dos_select_byte2
    dos_select_byte2 = dos_select_byte2>>2; // dont care about lsb
    for(uint8_t idx=0; idx<3; idx++){
        // looping 4 times bc dos_select_byte1 has data for 4 days
        int temp = dos_select_byte2>>(idx*2) & 0b11;
        uint8_t rolling_idx = 2 - idx;
        dos_select2[rolling_idx] = uint8_t(temp+1);
    }

    // loop thru day select and if select is on, begin sort
    for(uint8_t idx=0; idx<NUM_DAYS; idx++){
        uint8_t dosage;
        if(day_select_data[idx]){
            // look at corresponding dosage
            if(idx<4){
                // look at dos_select_byte1
                dosage = dos_select1[idx];
            }
            else{
                // look at dos_select_byte2
                dosage = dos_select2[idx-4];
            }
            String debug = "PillDispenser.cpp: " + dayReference[idx] + " needs " + String(dosage) + " pills...";
            DEBUG.println(debug);
            // get required pills from hopper
            _hop.transfer_pills(dosage);

            DEBUG.println("PillDispenser.cpp: Hopper transfer complete, beginning linear rail transfer...");

            delay(10);  // comment out later?

            // transfer from linear rail
            _lr.dispense_by_day(idx);
            
        }
    }
    _hop.reset_arm();

    // done :)
    _speaker.play_tune();
}


int PillDispenser::dispense_pills(){
    _sh.flush_buffer();
    while (true)
    {
        _message = _sh.receive_message();
        for(uint8_t idx = 0; idx<8; idx++){
            String debug = "PillDispenser.cpp: Serial message index " + String(idx) + " with data ";
            DEBUG.println(debug);
            DEBUG.print(_message[idx], HEX);
            DEBUG.println();
        } 
        int err = 0;
        int header_byte = _message[1];
        if(header_byte == 0x12){
            err = this->begin_pill_sort(_message);
            _sh.flush_buffer();
        }
        else if (header_byte == 0x21)
        {
            // begin flush
            this->begin_flush();
        }        
        else{
            DEBUG.println("PillDispenser.cpp: Begin pill sort encountered error. Oops.");
        }
    }   
}

int PillDispenser::begin_flush(){
    // runs flush code until we receive end flush
    DEBUG.println("PillDispenser.cpp: Beginning flush...");
    int* message;
    _hop.set_funnel_size(uint8_t(5));
    while(true){
        // run disk code but ignore pill count
        if(_sh.is_empty()){
            _hop.flush_pills();
        }
        else{
            // something in buffer, is it end flush?
            DEBUG.println("Looking for end flush...");
            message = _sh.receive_message();
            int command_byte = message[1];
            if(command_byte == 0x32){
                // done
                DEBUG.println("PillDispenser.cpp: End flush byte received.");
                _hop.reset_arm();
                return 0;
            }
            // keep goin...
        }
    }

}