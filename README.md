# pill-dispenser-ard-lib
Library used to interface with the Automatic Pill Dispenser device (v3.0).

## Description
For use only with the Automatic Pill Dispenser device. 

## Getting Started
# Dependencies
* Arduino IDE
* ELEGOO Arduino Mega 2560
* [Stepper Library](https://github.com/arduino-libraries/Stepper)
* [AccelStepper Library](https://github.com/waspinator/AccelStepper)

# Installing
To install, download the repo as a .ZIP and add to Arduino IDE-> Sketch -> Include Library -> Add .ZIP Library.

# Usage
Add the following lines of code to the beginning of your sketch file:
```cpp
#include <PillDispenser.h>
#include <SerialHandler.h>
```

The PillDispenser class is responsible for handling the physical components of the device itself. The SerialHandler
object, on the other hand, is responsible for parsing serial messages sent from the Nextion screen which the PillDispenser
object can then interpret and perform the expected operations described in the Firmware Readiness Report. 

The SerialHandler object occupies both the USB-Serial and Serial1 ports on the Arduino Mega 2560 with the USB-Serial port being used for Debugging purposes and is not required to run the program.

# Example Sketch
Fill later...

## Authors
Fill later...

## Version History

* 0.1
    * Initial Release

## License

???