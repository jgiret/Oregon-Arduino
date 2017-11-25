/*
* @Author: Jean-Christophe Giret
* @Date:   2017-11-19 00:25:21
* @Last Modified by:   Jean-Christophe Giret
* @Last Modified time: 2017-11-25 18:20:12
*/

#include "gtest/gtest.h"
#include "DecodeOOK/DecodeOOK.h"
#include "DecodeOOK/OregonDecoderV2.h"
#include "DecodeOOK/OregonDecoderV3.h"


/*
Dummy test to check if the Oregon Decoder V2 state is initialized with UNKNOWN
 */
TEST(OregonDecoderV2, decode) {
  OregonDecoderV2 ov2;
  byte state = static_cast<byte>(DecodeOOK::UNKNOWN);
  ASSERT_EQ(ov2.getState(), state);
}

/*
Dummy test to check if the Oregon Decoder V2 state is initialized with UNKNOWN
 */
TEST(OregonDecoderV3, decode) {
  OregonDecoderV3 ov3;
  byte state = static_cast<byte>(DecodeOOK::UNKNOWN);
  ASSERT_EQ(ov3.getState(), state);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

