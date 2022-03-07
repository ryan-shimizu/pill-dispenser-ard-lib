#include "Arduino.h"
#include "LinearRailFlap.h"
#define DEBUG Serial

LinearRailFlap::LinearRailFlap(uint8_t _flap_pin){
    this->_flap_pin = _flap_pin;

    // TODO: setup servos here

    // report to debug
    DEBUG.println("LinearRailFlap.cpp: LinearRailFlap object initialized.");
};

void LinearRailFlap::openServo(){
    /*
     * Function that opens the servo that allows the pill to drop
     * through the linear rail funnel.
     *  Args:
     *      None
     *  Returns:
     *      None
     */

    // TODO: Implement
    DEBUG.println("LinearRailFlap.cpp: Flap opened...");
};

void LinearRailFlap::closeServo(){
    /*
     * Function that closes the servo to prevent pills from falling
     * through the linear rail funnel.
     *  Args:
     *      None
     *  Returns:
     *      None
     */

    // TODO: Implement
    DEBUG.println("LinearRailFlap.cpp: Flap closed...");
}