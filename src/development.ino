#include "PillDispenser.h"
#include "SerialHandler.h"
#include "Speaker.h"
#include "LinearRail.h"
#include "LinearRailFlap.h"
// #include "PillDispenser.h"
// #include "SerialHandler.h"
#include "Hopper.h"
#define DEBUG Serial

void setup(){

    // Serial.begin(9600);
    // LinearRail lr(uint8_t(6), uint8_t(11), uint8_t(10), uint8_t(3));
    // lr.dispense_by_day(3);
    // delay(400);
    // LinearRailFlap lrf(uint8_t(6));
    // delay(400);
    // lrf.openServo();
    // lrf.closeServo();

    PillDispenser pd(
            //rail_step_pin
            10,

            //rail_dir_pin
            11,

            //flap_pin
            6,

            //ir_pin
            19,

            //disk_pin
            12,

            //disk_dir_pin
            13,

            //actuator_pin
            8,

            //actuator_dir_pin
            9,

            //speaker_pin
            5,

            //rail_limit_switch
            3,
            
            //actuator_limit_switch
            2
    );
    pd.dispense_pills();
}   

void loop(){
 

}