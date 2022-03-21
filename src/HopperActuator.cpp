#include "HopperActuator.h"
#define DEBUG Serial

HopperActuator::HopperActuator(uint8_t actuator_pin, uint8_t actuator_dir_pin){
    this->_actuator_pin = actuator_pin;
    this->_actuator_dir_pin = actuator_dir_pin;
    pinMode(actuator_dir_pin, OUTPUT);
    pinMode(actuator_pin, OUTPUT);
    // TODO: setup direction and rest of this constructor
    DEBUG.println("HopperActuator.cpp: HopperActuator object initialized.");
}