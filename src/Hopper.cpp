#include "Hopper.h"
#include "globals.h"
#define DEBUG Serial
#define STEPSIZE 50
#define STEP_PER_REV 200

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
     *  Returns:
     *      None
     */

    DEBUG.print("Hopper.cpp: Beginning transfer of pills of size ");
    DEBUG.print(num);
    DEBUG.println();

    // clearing in case accidental increment before function call
    _ir.clear_count();

    // actuator calculations
    int full_rev = STEP_PER_REV;
    int temp = 0;
    uint8_t actuator_level = 0;         // start at level 0
    uint8_t prev_count = 0;

    // NOTE: may be jittery depending on stepsize and overhead (test this)
    while(!_ir.check_pill_count(num)){
        _hd.rotate_disk(STEPSIZE);
        delay(100);     // delete later?
        temp++;
        if(temp>=full_rev){
            if(g_pill_count==prev_count){
                // pills did not pass thru beam since last rev
                // adjust level
                actuator_level++;
                this->_ha.set_level(actuator_level);
            }
            prev_count = g_pill_count;
            temp = 0;
        }
    }

    // clear again for next call
    _ir.clear_count();
    _ha.reset_arm();
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
}