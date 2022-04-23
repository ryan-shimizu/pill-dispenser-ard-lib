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
<<<<<<< Updated upstream
    // SerialHandler sh;
    // message = sh.receive_message();
    // for(int idx = 0; idx<8; idx++){
    //     DEBUG.println(message[idx], HEX);
    // }
    Serial.begin(9600);

    Hopper hop(uint8_t(12), uint8_t(13), uint8_t(8), uint8_t(9), uint8_t(19));
    // hop.reset_arm();
    // hop.reset_arm();
    hop.transfer_pills(4);
    Serial.println("Main finished...");
=======

    // Serial.begin(9600);
    // LinearRail lr(uint8_t(6), uint8_t(11), uint8_t(10));
    // lr.dispense_by_day(3);
    
    // LinearRailFlap lrf(uint8_t(6));
    // lrf.openServo();
    // lrf.closeServo();

    int* message;
    SerialHandler sh;
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
    while(true){
        message = sh.receive_message();
        for(uint8_t idx = 0; idx<8; idx++){
            String debug = "main.ino: Serial message index " + String(idx) + " with data ";
            DEBUG.print(message[idx], HEX);
        } 
        int err = pd.begin_pill_sort(message);
        if(err==1){
            DEBUG.println("main.ino: Begin pill sort encountered error code 1. Oops.");
        }
    }
>>>>>>> Stashed changes
}   

void loop(){
 

}