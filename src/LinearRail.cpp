#include "LinearRail.h"
#include <Stepper.h>
#define DEBUG Serial



const int FLAPOPENTIME = 500;
const int DAYSTEP = 140;



LinearRail::LinearRail(uint8_t flap_pin, uint8_t rail_dir_pin, uint8_t rail_step_pin )
    : _lr_flap(flap_pin)       // initializing LinearRailFlap
{
    this->_flap_pin = flap_pin;       // why arent we using the parameters? ,
    this->_rail_dir_pin = rail_dir_pin;
    this->_rail_step_pin = rail_step_pin;
    // TODO: setup the rest of this function for stepper motor rail

   Serial.begin(9600);
    
//SETUP MOTOR A //Rail

pinMode(_rail_dir_pin, OUTPUT);
pinMode(_rail_step_pin, OUTPUT);
digitalWrite(_rail_dir_pin,LOW); //LOW = CCW HIGH = CW


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

const int delay= 400;
 int count = 0;
 digitalWrite(_rail_dir_pin,direction);
  // put your main code here, to run repeatedly:
  
 
  

       while (count < daySteps ){    // SPIN if UNbroken
        digitalWrite(_rail_step_pin, HIGH);
       
        delayMicroseconds(delay);
        digitalWrite(_rail_step_pin, LOW);
       
        delayMicroseconds(delay); //range of delay 500- 1200 fast motor to slow; 1350 seems alright 4000 seems okay for disk
        count++;
        }

    }















    
}