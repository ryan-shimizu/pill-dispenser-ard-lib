/*
 * SerialHandler.cpp - Used to handle all serial tasks for Automatic Pill Dispenser
 * Created by Team Licensed to Pill, March 4, 2022
 * Do not distribute without explicit permission.
 */

#include "SerialHandler.h"
#include "Arduino.h"

#define DEBUG Serial
#define NEXTION Serial2
#define BUF_SIZE 8
#define BAUD 9600

SerialHandler::SerialHandler(){
    // constructor for SerialHandler

    // initialize serial
    DEBUG.begin(BAUD);
    NEXTION.begin(BAUD);

    // report initialization
    DEBUG.print("SerialHandler.cpp: Serial Handler initialized.\n");

}

int* SerialHandler::receive_message(){
    /*
     * Function that receives message from Serial buffer
     * and places it in 8 byte array for use in
     * PillDispenser::parse_message()
     *  
     *  Args:
     *      None
     *  Returns:
     *      return_array(int*):      8-element array containing all 8 bytes from serial buffer
     */

    // uint8_t byte_idx = 0;       // for termination counting, uncomment if we dont use lazy method
    delay(50);      // in case serial message is being transmitted at startup, may not need
    static int return_array[8];
    // this->_flush_buffer();

    while(true){
        if(NEXTION.available() > 7){        // all 8 bytes ready
            int bufferByte = NEXTION.read();
            if(bufferByte != 0x23){
                // something happened, message is wrong
                DEBUG.println("SerialHandler.cpp: Beginning byte of serial message not as expected.");
                DEBUG.println(bufferByte, HEX);
                
                // unable to interpret data in the buffer so just flush out whatever is in there and start again.
                this->flush_buffer();
                continue;
            }

            // valid message received, continue parsing
            return_array[0] = bufferByte;
            bufferByte = NEXTION.read();

            // command byte parsing
            bool invalidByteFound = false;
            switch(bufferByte){
                case 0x12:
                    DEBUG.println("SerialHandler.cpp: Found BeginSort byte.");
                    return_array[1] = bufferByte;

                    // read next 6 bytes, lazy method
                    return_array[2] = NEXTION.read();  // day select byte
                    return_array[3] = NEXTION.read();  // dosage select byte 1
                    return_array[4] = NEXTION.read();  // dosage select byte 2
                    DEBUG.println("SerialHandler.cpp: Data bytes read and saved to buffer.");
                    
                    // TODO: implement sanity check to make sure end bytes are 0xFF
                    return_array[5] = NEXTION.read();  // end byte
                    return_array[6] = NEXTION.read();  // end byte
                    return_array[7] = NEXTION.read();  // end byte
                    this->flush_buffer();
                    return return_array;       // TODO: double check return type
                    // break;
                // place any other command bytes cases here
                case 0x21:
                    DEBUG.println("SerialHandler.cpp: Found begin flush byte.");
                    return_array[1] = bufferByte;
                    
                    // read next 6 bytes, lazy method
                    return_array[2] = NEXTION.read();  // day select byte
                    return_array[3] = NEXTION.read();  // dosage select byte 1
                    return_array[4] = NEXTION.read();  // dosage select byte 2
                    DEBUG.println("SerialHandler.cpp: Data bytes read and saved to buffer.");
                    
                    // TODO: implement sanity check to make sure end bytes are 0xFF
                    return_array[5] = NEXTION.read();  // end byte
                    return_array[6] = NEXTION.read();  // end byte
                    return_array[7] = NEXTION.read();  // end byte
                    this->flush_buffer();
                    return return_array;       // TODO: double check return type
                
                case 0x32:
                    DEBUG.println("SerialHandler.cpp: Found end flush byte.");
                    return_array[1] = bufferByte;
                    
                    // read next 6 bytes, lazy method
                    return_array[2] = NEXTION.read();  // day select byte
                    return_array[3] = NEXTION.read();  // dosage select byte 1
                    return_array[4] = NEXTION.read();  // dosage select byte 2
                    DEBUG.println("SerialHandler.cpp: Data bytes read and saved to buffer.");
                    
                    // TODO: implement sanity check to make sure end bytes are 0xFF
                    return_array[5] = NEXTION.read();  // end byte
                    return_array[6] = NEXTION.read();  // end byte
                    return_array[7] = NEXTION.read();  // end byte
                    this->flush_buffer();
                    return return_array;       // TODO: double check return type

                
                // unknown command byte found
                default:
                    DEBUG.println("SerialHandler.cpp: Unknown command byte parsed.");
                    DEBUG.println(bufferByte, HEX);
                    invalidByteFound = true;
                    break;
            }
            if(invalidByteFound){
                // unable to interpret data in the buffer so just flush out whatever is in there and start again.
                this->flush_buffer();
                invalidByteFound = false;
                continue;
            }
        }
        else{
            delay(500);         // for development purposes, preventing serial monitor cluttering
            //delay(30);        // TODO: uncomment before final implementation
            DEBUG.println("SerialHandler.cpp: No message received yet...");
        }
    }
}

void SerialHandler::flush_buffer(){
    /*
     * Helper function to flush buffer in case of
     * uninterpretable message.
     *  Args:
     *      None
     *  Returns:
     *      None
     */
    while(NEXTION.available() > 0){
        NEXTION.read();
    }
    DEBUG.println("SerialHandler.cpp: Successfully flushed out buffer.");
}

bool SerialHandler::is_empty(){
    return (NEXTION.available() == 0);
}