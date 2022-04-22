#include "IRSensor.h"
#include "globals.h"
#define DEBUG Serial

IRSensor::IRSensor(uint8_t ir_pin){
    this->_ir_pin = ir_pin;
    pinMode(ir_pin, INPUT_PULLUP);
    digitalWrite(ir_pin, HIGH);
    attachInterrupt(digitalPinToInterrupt(ir_pin), increment_g_pill_count, FALLING);

    DEBUG.println("IRSensor.cpp: Checking global variable...");
    DEBUG.println(g_pill_count);
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
    //DEBUG.print(this->_pill_count);
    DEBUG.print(g_pill_count);
    DEBUG.println();
    // DEBUG.println("IRSensor.cpp: IR Sensor state: ");
    // DEBUG.println(digitalRead(_ir_pin));
    //return(this->_pill_count >= count);
    return(g_pill_count >= count);
}

void IRSensor::clear_count(){
    /*
     * Function that clears global pill count.
     *  Args:
     *      None
     *  Returns:
     *      None 
     */
    g_pill_count = 0;
}

