#ifndef PINREADER_H
#define PINREADER_H

#include <Arduino.h> 

class PinReader
{
public:    
    void init() {
        pinMode(8, INPUT_PULLUP);
        pinMode(9, INPUT_PULLUP);
        pinMode(10, INPUT_PULLUP);
        pinMode(11, INPUT_PULLUP);
        pinMode(12, INPUT_PULLUP);
        pinMode(13, INPUT_PULLUP);
    }

    int read(){
        int val = 0;
        if (digitalRead(8) == LOW)
        {
            val = val + 1;
        }
        if (digitalRead(9) == LOW)
        {
            val = val + 2;
        }
        if (digitalRead(10) == LOW)
        {
            val = val + 4;
        }
        if (digitalRead(11) == LOW)
        {
            val = val + 8;
        }
        if (digitalRead(12) == LOW)
        {
            val = val + 16;
        }
        if (digitalRead(13) == LOW)
        {
            val = val + 32;
        }
        return val;
    }
};

#endif