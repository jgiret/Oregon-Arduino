#ifndef LCD_HPP
#define LCD_HPP

#include <Arduino.h>
#include <LiquidCrystal.h>

#include "Utils/Utils.h"

class LCD {
 private:
  /*
  Pointer to the LiquidCrysal handler
   */
  LiquidCrystal* _screen;

 public:
  /**
   * @brief Default constructor
   * @details  Default LCD constructor: store the LiquisCrystal adress in
   * _screen handler
   */
  LCD(LiquidCrystal*);

  /**
   * @brief Update the LCD display
   * @details Update the display with the temperature and humidity passed as
   * arguments.
   *
   * @param temperature Temperature to display
   * @param humidity Humidity to display
   * @return Return 0 if OK
   */
  int update(float temperature, float humidity);

  /**
   * @brief Init the display
   * @details [long description]
   * @return Return 0 if OK
   */
  int init();
};

#endif