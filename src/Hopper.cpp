#include "Hopper.h"
#include "globals.h"
#define DEBUG Serial
#define STEPSIZE 400
#define STEP_PER_REV 10

Hopper::Hopper(uint8_t disk_pin, uint8_t disk_dir_pin, uint8_t actuator_pin, uint8_t actuator_dir_pin, uint8_t ir_pin)
    : _ha(actuator_pin=actuator_pin, actuator_dir_pin=actuator_dir_pin), 
    _hd(disk_pin=disk_pin, disk_dir_pin=disk_dir_pin), 
    _ir(ir_pin)    
{
    // do we need anything else...?
    DEBUG.println("Hopper.cpp: Hopper object initialized.");
}

void Hopper::transfer_pills(uint8_t num){
    /*
     * Function that takes in an x number of pills (1-4)
     * and rotates disk until x number of pills have passed
     * through the IR beam and then stops.
     * Need help on this...
     *  Args:
     *      num(uint8_t):       Number between 1-4,
     *                          when num == 0, treat as indefinite count
     *  Returns:
     *      None
     */

    DEBUG.print("Hopper.cpp: Beginning transfer of pills of size ");
    DEBUG.print(num);
    DEBUG.println();

    // clearing in case accidental increment before function call
    //_ir.clear_count(num);

    // fk that ^
    if(_ir.check_pill_count(1) && num==1){
        // we got something in limbo...edge case!
        // get the stuck pill out and end
        DEBUG.println("Hopper.cpp: Edge case encountered. 1 pill selected when 1 has already passed thru beam.");
        DEBUG.println("Hopper.cpp: Attempting to flush the one pill out of the system in case it is stuck in limbo...");
        _hd.rotate_disk(200, true);
        delay(100);     // test this
        _hd.rotate_disk(0, true);
        _ir.clear_count(1);
        return;
    }

    // actuator calculations
    int full_rev = STEP_PER_REV;
    int temp = 0;
    uint8_t actuator_level = 0;         // start at level 0
    uint8_t prev_count = 0;

    _hd.rotate_disk(200, true);
    while(!_ir.check_pill_count(num)){
        delay(400);     // delete later?
        temp++;
        if(temp>=full_rev){
            if(g_pill_count==prev_count){
                // pills did not pass thru beam since last rev
                // adjust level
                actuator_level++;
                if(actuator_level <= 5){
                    this->_ha.set_level(actuator_level);
                }
            }
            prev_count = g_pill_count;
            temp = 0;
            DEBUG.println("Hopper.cpp: Disc has completed one full revolution.");
        }
    }
    delay(290);
    _hd.rotate_disk(0, true);

    // wait for pills to drop
    delay(500);

    // clear again for next call
    _ir.clear_count(num);
    //_ha.reset_arm();
    DEBUG.println("Hopper.cpp: Done transferring pills to Linear rail.");
}

void Hopper::set_funnel_size(uint8_t num){
    /*
     * Function that adjusts funnel size using HopperActuator.
     * Args:
     *     num(uint8_t):       Number between 0-4, 
     * Returns:
     *     None
     */

    // TODO: Implement
    DEBUG.print("Hopper.cpp: Setting funnel size to ");
    DEBUG.print(num);
    DEBUG.println();
    _ha.set_level(num);
}

void Hopper::reset_arm(){
    _ha.reset_arm();
}

void Hopper::flush_pills(){
    DEBUG.println("Hopper.cpp: Attempting to flush pills... ");

    // actuator calculations
    int full_rev = STEP_PER_REV;
    int temp = 0;
    uint8_t prev_count = 0;
    uint8_t actuator_level = 5;
    _ha.curr_level = actuator_level;
    long long unsigned int count = 0;

    // NOTE: may be jittery depending on stepsize and overhead (test this)
    _hd.rotate_disk(200, true);
    while(count <= 5){
        delay(100);
        temp++;
        if(temp>=full_rev){
            temp = 0;
            DEBUG.println("Hopper.cpp: Disc has completed one full revolution.");
            count++;
        }
    }
    delay(290);
    _hd.rotate_disk(0, true);

    // clear for next run
    _ir.clear_count(99);
    DEBUG.println("Hopper.cpp: Done transferring pills to Linear rail.");   
}