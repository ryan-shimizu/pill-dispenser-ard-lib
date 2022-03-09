#include "Hopper.h"
#define DEBUG Serial

Hopper::Hopper(uint8_t disk_pin, uint8_t actuator_pin, uint8_t ir_pin)
    : _ha(actuator_pin), _hd(disk_pin), _ir(ir_pin)    
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

    // TODO: Implement



while (!_ir.check_pill_count(num)){


_hd.rotate_disk();
				}















    DEBUG.print("Hopper.cpp: Beginning transfer of pills of size ");
    DEBUG.print(num);
    DEBUG.println();
}

void Hopper::set_funnel_size(uint8_t num){
    /*
     * Function that adjusts funnel size using HopperActuator.
     * Args:
     *     num(uint8_t):       Number between 1-4, 
     * Returns:
     *     None
     */

    // TODO: Implement
    DEBUG.print("Hopper.cpp: Setting funnel size to ");
    DEBUG.print(num);
    DEBUG.println();
}