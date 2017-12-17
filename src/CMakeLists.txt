#=============================================================================#
# Author: Jean-Christophe Gitet                                               #
# Date: 18 nov. 2017                                                          #
#                                                                             #
# Description: Oregon-Arduino Cmake                                           #
#                                                                             #
#=============================================================================#

cmake_minimum_required(VERSION 2.8)
get_filename_component(PARENT_DIR ${CMAKE_CURRENT_SOURCE_DIR} DIRECTORY)
set(CMAKE_TOOLCHAIN_FILE ${PARENT_DIR}/cmake/ArduinoToolchain.cmake) # Arduino Toolchain
set(ARDUINO_SDK_PATH /Applications/Arduino.app/Contents/Java/)


#====================================================================#
#  Setup Project                                                     #
#====================================================================#
project(Oregon-Arduino-Build C CXX)

set(ARDUINO_DEFAULT_PORT /dev/tty.usbmodemFD1221) # Default Port, when not specified
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-threadsafe-statics")


file(GLOB SOURCES_OOK
 	${PARENT_DIR}/src/DecodeOOK/*.cpp
 	${PARENT_DIR}/src/DecodeOOK/*.h
 	${PARENT_DIR}/src/LCD/*.cpp
 	${PARENT_DIR}/src/LCD/*.h
 	${PARENT_DIR}/src/Utils/*.cpp
 	${PARENT_DIR}/src/Utils/*.h
 	)


print_board_list()
print_programmer_list()
link_directories(${PARENT_DIR}/libs)
set(uno.build.mcu "atmega328p")
generate_arduino_firmware(oregon_arduino
    SRCS ${PARENT_DIR}/src/oregon_arduino.cpp ${SOURCES_OOK}
    BOARD uno)
