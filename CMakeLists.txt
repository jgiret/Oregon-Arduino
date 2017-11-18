#=============================================================================#
# Author: Jean-Christophe Gitet                                               #
# Date: 18 nov. 2017                                                          #
#                                                                             #
# Description: Oregon-Arduino Cmake                                           #
#                                                                             #
#=============================================================================#
set(CMAKE_TOOLCHAIN_FILE cmake/ArduinoToolchain.cmake) # Arduino Toolchain
set(ARDUINO_SDK_PATH /Applications/Arduino.app/Contents/Java/)

cmake_minimum_required(VERSION 2.8)
#====================================================================#
#  Setup Project                                                     #
#====================================================================#
project(Oregon-Arduino C CXX)


print_board_list()
print_programmer_list()
print_programmer_settings(nano)
print_board_settings(nano)


set(ARDUINO_AVRDUDE_PROGRAM /Applications/Arduino.app/Contents/Java/hardware/tools/avr/bin/avrdude)
set(ARDUINO_AVRDUDE_CONFIG_PATH /Applications/Arduino.app/Contents/Java/hardware/tools/avr/etc/avrdude.conf) 
set(ARDUINO_DEFAULT_BOARD nano) # Default Board ID, when not specified
set(ARDUINO_DEFAULT_PORT /dev/cu.wchusbserialfd1220) # Default Port, when not specified

link_directories(${CMAKE_CURRENT_SOURCE_DIR}/libs)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-threadsafe-statics")

set(nano.build.mcu "atmega328p")
generate_arduino_firmware(oregon_arduino
        SRCS src/oregon_arduino.cpp
        BOARD nano)