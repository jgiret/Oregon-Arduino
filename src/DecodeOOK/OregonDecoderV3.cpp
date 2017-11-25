// Oregon V2 decoder added - Dominique Pierre
// Oregon V3 decoder revisited - Dominique Pierre
// New code to decode OOK signals from weather sensors, etc.
// 2010-04-11 <jcw@equi4.com> http://opensource.org/licenses/mit-license.php
// $Id: ookDecoder.pde 5331 2010-04-17 10:45:17Z jcw $

#include <Arduino.h>
#include "OregonDecoderV3.h"

OregonDecoderV3::OregonDecoderV3() {}

// add one bit to the packet data buffer
void OregonDecoderV3::gotBit (char value) {
    data[pos] = (data[pos] >> 1) | (value ? 0x80 : 00);
    total_bits++;
    pos = total_bits >> 3;
    if (pos >= sizeof data) {
        resetDecoder();
        return;
    }
    state = OK;
}

char OregonDecoderV3::decode (word width) {

    if (200 <= width && width < 1200) {
        byte w = width >= 700;
        switch (state) {
            case UNKNOWN:
                if (w == 0)
                    ++flip;
                else if (32 <= flip) {
                    flip = 1;
                    manchester(1);
                } else
                    return -1;
                break;
            case OK:
                if (w == 0)
                    state = T0;
                else
                    manchester(1);
                break;
            case T0:
                if (w == 0)
                    manchester(0);
                else
                    return -1;
                break;
        }
    } else {
        return -1;
    }
    return  total_bits == 80 ? 1: 0;
}