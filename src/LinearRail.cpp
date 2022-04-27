#include "LinearRail.h"
#include "Stepper.h"
#define DEBUG Serial

const int FLAPOPENTIME = 500;
const int DAYSTEP = 160;
const int STEPSIZE = 200;

LinearRail::LinearRail(uint8_t flap_pin, uint8_t rail_dir_pin, uint8_t rail_step_pin, uint8_t rail_limit_switch)
    : _lr_flap(flap_pin)       // initializing LinearRailFlap
{
    this->_flap_pin = flap_pin;
    this->_rail_dir_pin = rail_dir_pin;
    this->_rail_step_pin = rail_step_pin;
    this->_rail_limit_switch = rail_limit_switch;
    
//SETUP MOTOR A //Rail

    pinMode(_rail_dir_pin, OUTPUT);
    pinMode(_rail_step_pin, OUTPUT);
    pinMode(_rail_limit_switch, INPUT_PULLUP);
    digitalWrite(_rail_limit_switch, HIGH);

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
    long long unsigned int movedSteps = day*DAYSTEP;

    
    // reset in case we are off center
    this->_move_stepper_pwm();

    this->_move_stepper(movedSteps, false);  // move forward
    DEBUG.println("LinearRail.cpp: Moving forward...");
    delay(400);
    this->_drop_pill();
    delay(400);
    // this->_move_stepper(movedSteps, true); // move back to origin
    DEBUG.println("LinearRail.cpp: Moving back to origin...");
    this->_move_stepper_pwm();  // move back to origin

    

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

void LinearRail::_move_stepper(long long unsigned int daySteps, bool direction){
    /*
     * Function that drops the pill once the Linear Rail is
     * positioned over the correct day.
     *  Args:
     *      daySteps(int):      Steps to move the stepper motor
     *      direction(bool):    true = backward, false = forward
     *  Returns:
     *      None
     */

    const int delay = 800;
    int count = 0;
    if(direction){
    digitalWrite(_rail_dir_pin,LOW);
    }
    else{
    digitalWrite(_rail_dir_pin,HIGH);
    }
    //digitalWrite(_rail_dir_pin,direction);

    while (count < daySteps ){    // SPIN if UNbroken
        digitalWrite(_rail_step_pin, HIGH);
        
        delayMicroseconds(delay);
        digitalWrite(_rail_step_pin, LOW);
        
        delayMicroseconds(delay); //range of delay 500- 1200 fast motor to slow; 1350 seems alright 4000 seems okay for disk
        count++;
    }

}

void LinearRail::_move_stepper_pwm(){
    /*
     * Function that moves the LinearRail until the limit switch
     * is depressed.
     *  Args:
     *      None
     *  Returns:
     *      None
     */
    digitalWrite(_rail_dir_pin, LOW);  //test this direction
    analogWrite(_rail_step_pin, 254);   //start pwm

    // wait until limit switch is depressed
    while(digitalRead(_rail_limit_switch) != LOW);

    // stop pwm
    analogWrite(_rail_step_pin, 0);

}