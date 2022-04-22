#include "PillDispenser.h"
#include "SerialHandler.h"
#include "Speaker.h"
// #include "PillDispenser.h"
// #include "SerialHandler.h"
#include "Hopper.h"
#define DEBUG Serial

int* message;
void setup(){
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
}   

void loop(){

}