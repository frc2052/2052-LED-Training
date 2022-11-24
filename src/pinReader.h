#ifndef PINREADER_H
#define PINREADER_H

#include <Arduino.h> 

class PinReader
{
public:    
    void init() {
        //Ardunio has a built in pull up resistor for digital inputs
        //if the circuit is open, the pin will read high
        pinMode(8, INPUT_PULLUP);
        pinMode(9, INPUT_PULLUP);
        pinMode(10, INPUT_PULLUP);
        pinMode(11, INPUT_PULLUP);
        pinMode(12, INPUT_PULLUP);
        pinMode(13, INPUT_PULLUP);
    }

    //this will return 0 or 1
    //1 indicates the switch was closed (on)
    //0 indicates the switch was open (off)    
    int checkPinIsClosed(int pin){
        if (digitalRead(pin) == LOW) {
            return 1;
        } else {
            return 0;
        }
    }

    int read(){               
        int pin0 = checkPinIsClosed(8);
        int pin1 = checkPinIsClosed(9);
        int pin2 = checkPinIsClosed(10);
        int pin3 = checkPinIsClosed(11);
        int pin4 = checkPinIsClosed(12);
        int pin5 = checkPinIsClosed(13);

        //treat the pins as a binary number
        //001011 in binary is 0 + 0 + 8 + 0 + 2 + 1 = 11 
        int val =  (32 * pin5) + (16 * pin4) + (8 * pin3) + (4 * pin2) + (2 * pin1) + (1 * pin0);
        
        //the return value will be between 0 - 63
        return val;
    }
};

#endif