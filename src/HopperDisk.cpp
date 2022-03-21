#include "HopperDisk.h"
#include "Stepper.h"
#define DEBUG Serial
#define STEPS 200
#define SPEED 30

HopperDisk::HopperDisk(uint8_t disk_pin, uint8_t disk_dir_pin)
    :_disk(STEPS, disk_pin, disk_dir_pin)
{
    this->_disk_pin = disk_pin;
    this->_disk_dir_pin = disk_dir_pin;
    this->_disk.setSpeed(SPEED);
};

void HopperDisk::rotate_disk(uint8_t steps){
    /*
     * Function that rotates disk by a given number of steps
     *  Args:
     *      steps(uint8_t)      Max step size dictated by max uint8_t (256)
     *  Returns:
     *      None
     */
    this->_disk.step(steps);
    DEBUG.println("HopperDisk.cpp: Rotating disk...");
}