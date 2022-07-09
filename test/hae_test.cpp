// gtest
#include <gtest/gtest.h>

// hae
#include <hae.hpp>

#define eq EXPECT_EQ

using namespace hae;

TEST(Test, test)
{
  Hae engine;
    eq(engine.remaining_pending_sources_count(), hae::SOURCE_COUNT);
}