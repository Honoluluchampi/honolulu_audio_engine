// std
#include <cmath>
#include <limits>

// hae
#include <hae.hpp>
#include <hae_audio_data.hpp>

using namespace hae;

int main()
{
  Hae audio_engine;
  HaeAudioData audio_data;

  // audio creation
  const size_t freq = 44100;
  const float pitch = 440.0f;
  const float duration = 2.0f;
  std::vector<ALshort> audio(freq * duration);
  for (int i = 0; i < audio.size(); i++) {
    audio[i] = std::sin(pitch * M_PI * 2.0 * i / freq) * std::numeric_limits<ALshort>::max();
  }

  // audio data creation
  audio_data
    .set_sampling_rate(freq)
    .set_sampling_rate(AL_FORMAT_MONO16)
    .set_data(std::move(audio));

  audio_engine.bind_audio_to_buffer(audio_data);
}