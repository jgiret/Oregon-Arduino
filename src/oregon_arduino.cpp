/*
* @Author: Jean-Christophe Giret
* @Date:   2017-11-19 00:07:36
* @Last Modified by:   Jean-Christophe Giret
* @Last Modified time: 2017-11-19 17:37:19
*/

#include <Arduino.h>
#include <ArduinoJson.h>
#include <Time.h>

#include "DecodeOOK/OregonDecoderV2.h"
#include "DecodeOOK/OregonDecoderV3.h"

OregonDecoderV2 orscV2;
OregonDecoderV3 orscV3;

#define PORT 2

volatile word pulse;


void ext_int_1(void) {
    static word last;
    // determine the pulse length in microseconds, for either polarity
    pulse = micros() - last;
    last += pulse;
}

float temperature(const byte* data)
{
    int sign = (data[6]&0x8) ? -1 : 1;
    float temp = ((data[5]&0xF0) >> 4)*10 + (data[5]&0xF) + (float)(((data[4]&0xF0) >> 4) / 10.0);
    return sign * temp;
}
 
byte humidity(const byte* data)
{
    return (data[7]&0xF) * 10 + ((data[6]&0xF0) >> 4);
}
 
// Ne retourne qu'un apercu de l'etat de la baterie : 10 = faible
byte battery(const byte* data)
{
    return (data[4] & 0x4) ? 0 : 1;
}
 
byte channel(const byte* data)
{
    byte channel;
    switch ((data[2] & 0xF0) >> 4)
    {
        case 0x1:
            channel = 1;
            break;
        case 0x2:
            channel = 2;
            break;
        case 0x4:
            channel = 3;
            break;
     }
 
     return channel;
}
 
void reportSerial (const char* s, class DecodeOOK& decoder)
{
    byte pos;
    const byte* data = decoder.getData(pos);

    StaticJsonBuffer<400> jsonBuffer;
    JsonObject& root = jsonBuffer.createObject();

    char * buffer;

        if (data[0] == 0xFA && data[1] == 0x28){
          buffer="THGR810";
        }
         else{
          buffer="Unknown";
         }
        
        root["device"] = buffer;
        root["device_id"] = data[3];
        root["temperature"] = temperature(data);
        root["humidity"] = humidity(data);
        root["channel"] = channel(data);
        root["hour"] = hour();
        root["minute"] = minute();
        root["second"] = second();
       
        root.printTo(Serial);
        Serial.print('\n');
        decoder.resetDecoder();
}


void setup () { 
   Serial.begin(115200);
   attachInterrupt(1, ext_int_1, CHANGE);
}

void loop () {
    static int i = 0;
    cli();
    word p = pulse;
    
    pulse = 0;
    sei();
    
    if (p != 0) {
        if (orscV2.nextPulse(p))
            reportSerial("OSV2", orscV2);  
        if (orscV3.nextPulse(p))
            reportSerial("OSV3", orscV3);              
    }

}