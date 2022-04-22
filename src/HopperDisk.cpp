#include "HopperDisk.h"
#include "Stepper.h"
#define DEBUG Serial
#define STEPS 200
#define SPEED 30

HopperDisk::HopperDisk(uint8_t disk_pin, uint8_t disk_dir_pin)
    //:_disk(STEPS, disk_pin, disk_dir_pin)
{
    this->_disk_pin = disk_pin;
    this->_disk_dir_pin = disk_dir_pin;
    pinMode(disk_dir_pin, OUTPUT);
    pinMode(disk_pin, OUTPUT);
    //this->_disk.setSpeed(SPEED);
};

void HopperDisk::rotate_disk(int duty_cycle, bool dir){
    /*
     * Function that rotates disk by a given number of steps
     *  Args:
     *      steps(uint8_t)      Max step size dictated by max uint8_t (256)
     *  Returns:
     *      None
     */
    // this->_disk.step(steps);
    DEBUG.println("HopperDisk.cpp: Rotating disk...");
    // const int delay=700;
    // long long int count = 0;
    if(dir){
        digitalWrite(_disk_dir_pin,HIGH);
    }
    else{
        digitalWrite(_disk_dir_pin,LOW);
    }
    // //digitalWrite(_rail_dir_pin,direction);

    // while (count < steps ){    // SPIN if UNbroken
    //     digitalWrite(_disk_pin, HIGH);
        
    //     delayMicroseconds(delay);
    //     digitalWrite(_disk_pin, LOW);
        
    //     delayMicroseconds(delay); //range of delay 500- 1200 fast motor to slow; 1350 seems alright 4000 seems okay for disk
    //     count++;
    // }

    analogWrite(_disk_pin, duty_cycle);
}