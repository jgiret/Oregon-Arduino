// Oregon V2 decoder added - Dominique Pierre
// Oregon V3 decoder revisited - Dominique Pierre
// New code to decode OOK signals from weather sensors, etc.
// 2010-04-11 <jcw@equi4.com> http://opensource.org/licenses/mit-license.php
// $Id: ookDecoder.pde 5331 2010-04-17 10:45:17Z jcw $

#ifndef OREGONDECODERV2_HPP
#define OREGONDECODERV2_HPP

#include "DecodeOOK.h"

class OregonDecoderV2 : public DecodeOOK {
public:
    OregonDecoderV2();
    virtual void gotBit (char value);
    virtual char decode (word width);
};

#endif