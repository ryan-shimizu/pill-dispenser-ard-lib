#include "LinearRail.h"
#define DEBUG Serial

const int FLAPOPENTIME = 500;
const int DAYSTEP = 140;   //test



LinearRail::LinearRail(uint8_t flap_pin, uint8_t rail_pin)
    : _lr_flap(_flap_pin)       // initializing LinearRailFlap
{
    this->_flap_pin = _flap_pin;
    this->_rail_pin = _rail_pin;

    // TODO: setup the rest of this function for stepper motor rail

    DEBUG.println("LinearRail.cpp: LinearRail object initialized.");
};

void LinearRail::dispense_by_day(uint8_t day){
    /*
     * Function that moves the linear rail to the correct
     * day.
     *  Args:
     *      day(uint8_t):       0-6, Sunday-Saturday, Left->Right
     *  Returns:
     *      None
     */

    DEBUG.print("LinearRail.cpp: Dispensing to day ");
    DEBUG.print(int(day));
    DEBUG.print("\n");

    // calculate steps required to move to requested day
    int movedSteps = day*DAYSTEP;

    this->_move_stepper(movedSteps, true);  // move forward
    this->_drop_pill();
    this->_move_stepper(movedSteps, false); // move back to origin

    // report to debug
    DEBUG.print("LinearRail.cpp: Finished dispensing to day ");
    DEBUG.print(int(day));
    DEBUG.print("\n");
};

void LinearRail::_drop_pill(){
    /*
     * Function that drops the pill once the Linear Rail is
     * positioned over the correct day.
     *  Args:
     *      None
     *  Returns:
     *      None
     */

    DEBUG.println("LinearRail.cpp: Dropping pill...");
    this->_lr_flap.openServo();
    delay(FLAPOPENTIME);
    this->_lr_flap.closeServo();
};

void LinearRail::_move_stepper(int daySteps, bool direction){
    /*
     * Function that drops the pill once the Linear Rail is
     * positioned over the correct day.
     *  Args:
     *      daySteps(int):      Steps to move the stepper motor
     *      direction(bool):    true = forward, false = backward
     *  Returns:
     *      None
     */

    // TODO: Implement
}