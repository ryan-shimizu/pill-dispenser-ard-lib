#include "PillDispenser.h"
#include "SerialHandler.h"
#define DEBUG Serial

int* message;
void setup(){
    SerialHandler sh;
    message = sh.receive_message();
    for(int idx = 0; idx<8; idx++){
        DEBUG.println(message[idx], HEX);
    }
}   

void loop(){
}