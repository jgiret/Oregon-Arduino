// Oregon V2 decoder added - Dominique Pierre
// Oregon V3 decoder revisited - Dominique Pierre
// New code to decode OOK signals from weather sensors, etc.
// 2010-04-11 <jcw@equi4.com> http://opensource.org/licenses/mit-license.php
// $Id: ookDecoder.pde 5331 2010-04-17 10:45:17Z jcw $

#include "DecodeOOK.h"
 
DecodeOOK::DecodeOOK () { resetDecoder(); }


byte DecodeOOK::getState(){
    return state;
}

bool DecodeOOK::nextPulse (word width) {

    if (state != DONE)
    
        switch (decode(width)) {
            case -1: resetDecoder(); break;
            case 1:  done(); break;
        }
    return isDone();
}

bool DecodeOOK::isDone () const { return state == DONE; }

const byte* DecodeOOK::getData (byte& count) const {
    count = pos;
    return data; 
}

void DecodeOOK::resetDecoder () {
    total_bits = bits = pos = flip = 0;
    state = UNKNOWN;
}

// add one bit to the packet data buffer
void DecodeOOK::gotBit (char value) {
    total_bits++; 
    byte *ptr = data + pos;
    *ptr = (*ptr >> 1) | (value << 7);

    if (++bits >= 8) {
        bits = 0;
        if (++pos >= sizeof data) {
            resetDecoder();
            return;
        }
    }
    state = OK;
}

// store a bit using Manchester encoding
void DecodeOOK::manchester (char value) {
    flip ^= value; // manchester code, long pulse flips the bit
    gotBit(flip);
}


void DecodeOOK::done () {
    while (bits)
        gotBit(0); // padding
    state = DONE;
}


// 433 MHz decoders