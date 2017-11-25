// Oregon V2 decoder added - Dominique Pierre
// Oregon V3 decoder revisited - Dominique Pierre
// New code to decode OOK signals from weather sensors, etc.
// 2010-04-11 <jcw@equi4.com> http://opensource.org/licenses/mit-license.php
// $Id: ookDecoder.pde 5331 2010-04-17 10:45:17Z jcw $

#ifndef DECODEOOK_HPP
#define DECODEOOK_HPP

#include <Arduino.h>

typedef uint16_t word ;

class DecodeOOK {

protected:
    byte total_bits;
    byte bits;
    byte flip;
    byte state;
    byte pos;
    byte data[25];

    virtual char decode (word width) =0;
    
public:

    //
    enum { UNKNOWN, T0, T1, T2, T3, OK, DONE };

    /**
     * @brief Class constructor
     * @details [long description]
     * @return None
     */
    DecodeOOK ();


    
    byte getState();


    /**
     * @brief [brief description]
     * @details [long description]
     * 
     * @param width [description]
     * @return [description]
     */
    bool nextPulse (word width);
    
    /**
     * @brief [brief description]
     * @details [long description]
     * @return [description]
     */
    bool isDone () const ;

    const byte* getData (byte& count) const ;
    
    void resetDecoder () ;
    
    // add one bit to the packet data buffer
    
    virtual void gotBit (char value) ;
    
    // store a bit using Manchester encoding
    void manchester (char value) ;
    
    // move bits to the front so that all the bits are aligned to the end
    void alignTail (byte max =0) ;
    
    void reverseBits () ;
    
    void reverseNibbles () ;

    void done();
};

#endif