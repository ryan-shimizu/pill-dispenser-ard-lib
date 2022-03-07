#include "HopperActuator.h"
#define DEBUG Serial

HopperActuator::HopperActuator(uint8_t actuator_pin){
    this->_actuator_pin = actuator_pin;

    // TODO: setup direction and rest of this constructor
    DEBUG.println("HopperActuator.cpp: HopperActuator object initialized.");
}