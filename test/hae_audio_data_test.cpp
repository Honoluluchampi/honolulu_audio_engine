// gtest
#include <gtest/gtest.h>

// hae
#include <hae.hpp>
#include <hae_audio_data.hpp>

#define eq EXPECT_EQ

using namespace hae;

TEST(audio_data, construct)
{
  HaeAudioData audio_data;
    eq(audio_data.sampling_rate(), 44100);
    eq(audio_data.buffer_id(), 0);
    eq(audio_data.format(), AL_FORMAT_MONO16);
}

TEST(audio_data, setter_getter)
{
  HaeAudioData data;
  data.set_data(std::vector<ALshort>{1000, 1000, 1000});
  data.set_sampling_rate(22050);
  data.set_format(AL_FORMAT_MONO8);

    eq(*data.data(), 1000);
    eq(data.sampling_rate(), 22050);
    eq(data.format(), AL_FORMAT_MONO8);
    eq(data.buffer_id(), 1);
  // ALshort is 16-bit
    eq(data.data_size_in_byte(), 3 * 2);
}