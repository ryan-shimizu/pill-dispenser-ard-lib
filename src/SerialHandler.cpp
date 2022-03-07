#include "SerialHandler.h"
#include "Arduino.h"

#define DEBUG Serial
#define NEXTION Serial1
#define BUF_SIZE 8
#define BAUD 9600

SerialHandler::SerialHandler(){
    // constructor for SerialHandler
    // flush buffer
    for(uint8_t idx = 0; idx<BUF_SIZE-1; idx++){
        this->_buffer[idx] = 0;
    }

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
     *      message(int*):      8-element array containing all 8 bytes from serial buffer
     */

    uint8_t byte_idx = 0;       // for termination counting
    delay(50);      // in case serial message is being transmitted at startup, may not need

    while(true){
        if(NEXTION.available() > 7){        // all 8 bytes ready
            int bufferByte = NEXTION.read();
            if(bufferByte != 0x23){
                // something happened, message is wrong
                DEBUG.print("SerialHandler.cpp: Beginning byte of serial message not as expected.\n");
                DEBUG.print(bufferByte, HEX);
                
                // unable to interpret data in the buffer so just flush out whatever is in there and start again.
                this->_flush_buffer();
                continue;
            }

            // valid message received, continue parsing
            this->_buffer[0] = bufferByte;
            bufferByte = NEXTION.read();

            // command byte parsing
            bool invalidByteFound = false;
            switch(bufferByte){
                case 0x12:
                    DEBUG.print("SerialHandler.cpp: Found BeginSort byte.\n");
                    this->_buffer[1] = bufferByte;

                    // read next 6 bytes, lazy method
                    this->_buffer[2] = NEXTION.read();  // day select byte
                    this->_buffer[3] = NEXTION.read();  // dosage select byte 1
                    this->_buffer[4] = NEXTION.read();  // dosage select byte 2
                    DEBUG.print("SerialHandler.cpp: Data bytes read and saved to buffer.");
                    
                    // TODO: implement sanity check to make sure end bytes are 0xFF
                    this->_buffer[5] = NEXTION.read();  // end byte
                    this->_buffer[6] = NEXTION.read();  // end byte
                    this->_buffer[7] = NEXTION.read();  // end byte
                    return this->_buffer;       // TODO: double check return type
                    // break;
                // place any other command bytes cases here
                
                // unknown command byte found
                default:
                    DEBUG.print("SerialHandler.cpp: Unknown command byte parsed.\n");
                    DEBUG.print(bufferByte, HEX);
                    invalidByteFound = true;
                    break;
            }
            if(invalidByteFound){
                // unable to interpret data in the buffer so just flush out whatever is in there and start again.
                this->_flush_buffer();
                continue;
            }
        }
        else{
            delay(500);         // for development purposes, preventing serial monitor cluttering
            //delay(30);        // TODO: uncomment before final implementation
            DEBUG.print("SerialHandler.cpp: No message received yet...\n");
        }
    }
}

void SerialHandler::_flush_buffer(){
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
    DEBUG.print("SerialHandler.cpp: Successfully flushed out buffer.\n");
}