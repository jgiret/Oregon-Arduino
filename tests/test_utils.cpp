/*
* @Author: Jean-Christophe Giret
* @Date:   2017-11-19 00:25:21
* @Last Modified by:   Jean-Christophe Giret
* @Last Modified time: 2017-12-05 22:00:55
*/
//#include <Arduino.h>

#include <stdio.h>
#include "gtest/gtest.h"
#include "Utils/Utils.h"


/*
Dummy test to check the concatenation
 */
TEST(concatenate, whenInputisValid_thenTestPass) {

char buffer[MAX_STRING_SIZE];
float bar = 50.2;
concatenate("Foo", bar, buffer);
ASSERT_STREQ(buffer,"Foo50.2");
}

TEST(concatenate, whenInputdoesNotFitInBuffer_thenConcatenateReturnNot0) {

char buffer[MAX_STRING_SIZE];
const char foo[] = "StringWhichIsLargerThan16_";
float bar = 50.2;
concatenate(foo, bar, buffer);
ASSERT_STREQ(buffer,"StringWhichIsLargerThan16_50.2");
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
