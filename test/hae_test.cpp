// gtest
#include <gtest/gtest.h>

// hae
#include <hae.hpp>
#include <hae_audio_data.hpp>

#define eq EXPECT_EQ

using namespace hae;

TEST(hae, ctor)
{
  Hae::start_hae_context();
    eq(Hae::remaining_pending_sources_count(), hae::SOURCE_COUNT);
}

TEST(hae, audio_process_functions)
{
  HaeAudioData audio_data;
  eq(Hae::bind_audio_to_buffer(audio_data), Result::SUCCESS);
  eq(Hae::bind_buffer_to_source(audio_data), Result::SUCCESS);

  eq(Hae::remaining_pending_sources_count(), hae::SOURCE_COUNT - 1);
  eq(audio_data.is_bound_to_buffer(), true);
  eq(audio_data.is_bound_to_source(), true);

  eq(Hae::remove_audio_from_source(audio_data), Result::SUCCESS);
  eq(Hae::remove_audio_resources(audio_data), Result::SUCCESS);

  eq(Hae::remaining_pending_sources_count(), hae::SOURCE_COUNT);
  eq(audio_data.is_bound_to_buffer(), false);
  eq(audio_data.is_bound_to_source(), false);
}

TEST(hae, dtor)
{
  Hae::kill_hae_context();
}