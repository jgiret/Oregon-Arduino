/*
 * @Author: Jean-Christophe Giret
 * @Date:   2017-11-26 18:18:22
 * @Last Modified by:   Jean-Christophe Giret
 * @Last Modified time: 2017-12-17 21:31:05
 */
#include "Utils.h"
#include <Arduino.h>

// Concatenate a char and a float
void concatenate(const char* header, float value, char* buffer) {
  char charVal[5];
  dtostrf(value, 3, 1, charVal);
  strncpy(buffer, header, MAX_STRING_SIZE - 1);
  strncat(buffer, charVal, MAX_STRING_SIZE - 1);
  return;
}
