#=============================================================================#
# Author: Jean-Christophe Gitet                                               #
# Date: 18 nov. 2017                                                          #
#                                                                             #
# Description: Oregon-Arduino Cmake                                           #
#                                                                             #
#=============================================================================#


#====================================================================#
#  Setup Project                                                     #
#====================================================================#
project(Oregon-Arduino-Tests C CXX)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-threadsafe-statics")
get_filename_component(PARENT_DIR ${CMAKE_CURRENT_SOURCE_DIR} DIRECTORY)

file(GLOB SOURCES_OOK
 	${PARENT_DIR}/src/DecodeOOK/*.cpp
 	${PARENT_DIR}/src/DecodeOOK/*.h)
	
enable_testing()

add_subdirectory(${PARENT_DIR}/libs/test/arduino-mock ${CMAKE_BINARY_DIR}/arduino-mock-build/)

include_directories(
	${PARENT_DIR}/src/
	${ARDUINO_MOCK_INCLUDE_DIRS}/arduino-mock/
    ${ARDUINO_MOCK_LIBS_DIR}/lib/gtest/gtest/src/gtest/include
    ${ARDUINO_MOCK_LIBS_DIR}/lib/gmock/gmock/src/gmock/include
	)

add_executable(tests test_oregonv2.cpp ${SOURCES_OOK})
add_dependencies(tests arduino_mock)

target_link_libraries(tests
    ${ARDUINO_MOCK_LIBS_DIR}/lib/gtest/gtest/src/gtest-build/libgtest.a
    ${ARDUINO_MOCK_LIBS_DIR}/lib/gmock/gmock/src/gmock-build/libgmock.a
    ${ARDUINO_MOCK_LIBS_DIR}/dist/lib/libarduino_mock.a
    ${CMAKE_THREAD_LIBS_INIT}
)

set (GTEST_LIBRARY /Users/jgiret/SOURCES/googletest/install/lib)
set (GTEST_MAIN_LIBRARY /Users/jgiret/SOURCES/googletest/install/lib)
set (GTEST_INCLUDE_DIR /Users/jgiret/SOURCES/googletest/include)
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

gtest_discover_tests(tests TEST_PREFIX new:)




