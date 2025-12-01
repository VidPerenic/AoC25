#include "../functions.h"
#include <gtest/gtest.h>

// Add your tests here
TEST(AoC2301, IsDigit) {
  EXPECT_TRUE(isDigit('0'));
  EXPECT_TRUE(isDigit('5'));
  EXPECT_TRUE(isDigit('9'));
  EXPECT_FALSE(isDigit('a'));
  EXPECT_FALSE(isDigit('/'));
  EXPECT_FALSE(isDigit(':'));
}

TEST(AoC2301, GetNumber) {
  EXPECT_EQ(getNumber("1abc2"), 12);
  EXPECT_EQ(getNumber("pqr3stu8vwx"), 38);
  EXPECT_EQ(getNumber("a1b2c3d4e5f"), 15);
  EXPECT_EQ(getNumber("treb7uchet"), 77);
}

TEST(AoC2301, GetNumberStr) {
  EXPECT_EQ(getNumberStr("two1nine"), 29);
  EXPECT_EQ(getNumberStr("eightwothree"), 83);
  EXPECT_EQ(getNumberStr("abcone2threexyz"), 13);
  EXPECT_EQ(getNumberStr("xtwone3four"), 24);
  EXPECT_EQ(getNumberStr("4nineeightseven2"), 42);
  EXPECT_EQ(getNumberStr("zoneight234"), 14);
  EXPECT_EQ(getNumberStr("7pqrstsixteen"), 76);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
