/*
 * Speaker.cpp - Speaker interface
 * Definition file for Speaker module
 * Created by Team Licensed to Pill, March 4, 2022
 */

#include "Arduino.h"
#include "Speaker.h"

Speaker::Speaker(uint8_t speaker_pin){
    this->_speaker_pin = speaker_pin;
    pinMode(speaker_pin, OUTPUT);
}

void Speaker::play_tune(){
// Plays tune at the end of the pill dispensing operation
    // TODO: Implement
}