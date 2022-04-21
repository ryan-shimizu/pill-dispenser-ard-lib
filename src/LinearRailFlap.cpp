#include "Arduino.h"
#include "LinearRailFlap.h"
#define DEBUG Serial
#define DELAYCONST 1000

LinearRailFlap::LinearRailFlap(uint8_t _flap_pin){
    this->_flap_pin = _flap_pin;
    _flap.attach(_flap_pin);
    _flap.write(0); 
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

    //_flap.write(0);     //might not need this
    //delay(1000);
    _flap.write(90);	//open flap
    delay(DELAYCONST);
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


    _flap.write(0);   //closing flap
    delay(DELAYCONST);

    DEBUG.println("LinearRailFlap.cpp: Flap closed...");
}