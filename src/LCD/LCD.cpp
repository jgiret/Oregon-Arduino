/*
 * @Author: Jean-Christophe Giret
 * @Date:   2017-11-26 18:07:47
 * @Last Modified by:   Jean-Christophe Giret
 * @Last Modified time: 2017-12-17 21:30:55
 */

#include "LCD.h"
#include "Utils/Utils.h"

// Constructor: set the LiquidCrystal Handler
LCD::LCD(LiquidCrystal* handler) { _screen = handler; }

// Update the LiquidCrystal display
int LCD::update(float temperature, float humidity) {
  _screen->clear();

  char temp[16];
  concatenate("Temp.: ", temperature, temp);
  _screen->setCursor(0, 0);
  _screen->print(temp);

  char hum[16];
  concatenate("Humidity: ", humidity, hum);
  _screen->setCursor(0, 1);
  _screen->print(hum);

  return 0;
}

// Init the LiquidCrystal display
int LCD::init() {
  _screen->begin(
      16, 2);  
  _screen->clear();             
  _screen->print("Temp.:");     
  _screen->setCursor(0, 1);    
  _screen->print("Humidity:"); 
  return 0;
}

