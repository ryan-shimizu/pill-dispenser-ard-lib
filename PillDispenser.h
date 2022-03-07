/*
 * PillDispenser.h - Library for Interfacing with Automatic Pill Dispenser Device
 * Created by Team Licensed to Pill, March 4, 2022
 */

#ifndef PillDispenser_h
#define PillDispenser_h
#include "Arduino.h"

class PillDispenser{
    public:
        PillDispenser(
        // constructor
            uint8_t linearRailPin;
            uint8_t linearRailServoPin;
            uint8_t irSensorPin;
            uint8_t hopperServoPin;
            uint8_t hopperActuatorPin;
        );
        void idle();
        int parseSerialMessage(int messageData[]);
        void sendDoneMessage();
        void sendErrorMessage(int errorCode=0);
        void begin_pill_sort();
    private:
        // physical components
        LinearRail* lr;
        LinearRailServo* lr_servo;
        IRSensor* ir_sen;
        HopperControl* hopper_ctrl;
        HopperActuator* hopper_act;
        SerialHandler* serial_io;

}

#endif
