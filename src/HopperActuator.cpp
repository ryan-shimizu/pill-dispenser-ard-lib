#include "HopperActuator.h"
#define DEBUG Serial

long long int LEVELSTEP = 4000;

HopperActuator::HopperActuator(uint8_t actuator_pin, uint8_t actuator_dir_pin){
    this->_actuator_pin = actuator_pin;
    this->_actuator_dir_pin = actuator_dir_pin;
    this->curr_level = 0;
    pinMode(actuator_dir_pin, OUTPUT);
    pinMode(actuator_pin, OUTPUT);
    // TODO: setup direction and rest of this constructor
    DEBUG.println("HopperActuator.cpp: HopperActuator object initialized.");
}

void HopperActuator::reset_arm(){
    // Resets arm to default state
    DEBUG.println("HopperActuator.cpp: Resetting arm...");
    long long int RESETSTEPS = LEVELSTEP*5;
    this->_move_stepper(RESETSTEPS, true);
}

void HopperActuator::set_level(uint8_t level){
    /*
     * Function that sets the level of the actuator
     * given its current level.
     *  Args:
     *      level(uint8_t)      Target level
     *  Returns:
     *      None
     */

    DEBUG.print("HopperActuator.cpp: Setting level to ");
    DEBUG.print(level);
    long long int delta = int(level) - int(curr_level);
    // use delta to determine direction to move stepper
    bool direction = delta<=0 ? true : false;
    this->_move_stepper(delta*LEVELSTEP, direction);
    curr_level = level;
}

void HopperActuator::_move_stepper(long long int steps, bool dir){
    /*
     * Function that moves the stepper motor a certain number of steps
     * in a given direction
     *  Args:
     *      steps(int):      Steps to move the stepper motor
     *      dir(bool):    true = forward, false = backward
     *  Returns:
     *      None
     */
    
    const int delay= 500;
    long long int count = 0;
    if(dir){
    digitalWrite(_actuator_dir_pin,HIGH);
    }
    else{
    digitalWrite(_actuator_dir_pin,LOW);
    }
    //digitalWrite(_rail_dir_pin,direction);

    while (count < steps ){    // SPIN if UNbroken
        digitalWrite(_actuator_pin, HIGH);
        
        delayMicroseconds(delay);
        digitalWrite(_actuator_pin, LOW);
        
        delayMicroseconds(delay); //range of delay 500- 1200 fast motor to slow; 1350 seems alright 4000 seems okay for disk
        count++;
    }
}