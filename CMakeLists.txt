#=============================================================================#
# Author: Jean-Christophe Gitet                                               #
# Date: 18 nov. 2017                                                          #
#                                                                             #
# Description: Oregon-Arduino Cmake                                           #
#                                                                             #
#=============================================================================#

cmake_minimum_required(VERSION 3.10)
include(ExternalProject)


option(UNIT_TEST "Enable unit tests" ON)

if(UNIT_TEST)
	MESSAGE("Unit test enabled")
	add_subdirectory(tests ${CMAKE_SOURCE_DIR}/tests)
endif()


ExternalProject_Add(src 
	SOURCE_DIR ${CMAKE_SOURCE_DIR}/src/
	INSTALL_COMMAND ""
	TEST_COMMAND "")

