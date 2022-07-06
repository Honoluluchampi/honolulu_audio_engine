// gtest
#include <gtest/gtest.h>

// hae
#include <hae.hpp>

TEST(Test, test)
{
  int i = 0;
  EXPECT_EQ(i, 0);
  i++;
  EXPECT_EQ(i, 1);
}