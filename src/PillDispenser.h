/*
 * PillDispenser.h - Library for Interfacing with Automatic Pill Dispenser Device
 * Created by Team Licensed to Pill, March 4, 2022
 */

#ifndef PillDispenser_h
#define PillDispenser_h
#include "Arduino.h"
#include "SerialHandler.h"

class PillDispenser{
    public:
        PillDispenser(
        // constructor
            uint8_t linearRailPin,
            uint8_t linearRailServoPin,
            uint8_t irSensorPin,
            uint8_t hopperServoPin,
            uint8_t hopperActuatorPin
        );
        void idle();
        void parseSerialMessage(int messageData[]);
        void sendDoneMessage();
        void sendErrorMessage(int errorCode=0);
        void begin_pill_sort();
    private:
        // internal components
        int _beginSortByte;
        int _daySelectByte;
        int _dosageSelectByte1;
        int _dosageSelectByte2;

        // physical components
        LinearRail* _lr;
        LinearRailServo* _lr_servo;
        IRSensor* _ir_sen;
        HopperControl* _hopper_ctrl;
        HopperActuator* _hopper_act;

};

#endif
