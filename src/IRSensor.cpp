#include "IRSensor.h"
#define DEBUG Serial

IRSensor::IRSensor(uint8_t ir_pin){
    this->_ir_pin = ir_pin;
    this->_pill_count = 0;
    // TODO: initialize the rest of the ir sensor

    DEBUG.println("IRSensor.cpp: IRSensor object initialized.");
};

// TODO: Implement interrupt handler to increment IRSensor._pill_count on beam break

bool IRSensor::check_pill_count(uint8_t count){
    /*
     * Function that returns true if count exceeds
     * internal count of pills and false if it does not.
     *  Args:
     *      count(uint8_t):     Number of pills to check count against
     *  Returns:
     *      bool:               True->count exceeds internal count
     *                          False->count does not exceed internal count  
     */
    DEBUG.print("IRSensor.cpp: Check called. Internal: ");
    DEBUG.print(this->_pill_count);
    DEBUG.println();
    DEBUG.print("IRSensor.cpp: Input: ");
    DEBUG.print(count);
    DEBUG.println();
    return(this->_pill_count >= count);
}
