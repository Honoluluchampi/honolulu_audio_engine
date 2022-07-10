// std
#include <thread>
#include <cmath>
#include <limits>

// hae
#include <hae.hpp>
#include <hae_audio_data.hpp>

using namespace hae;

int main()
{
  Hae::start_hae_context();

  // raw audio creation
  const unsigned int freq = 44100;
  const float pitch = 440.0f;
  const float duration = 2.0f;
  std::vector<ALshort> audio(static_cast<size_t>(freq * duration));
  for (int i = 0; i < audio.size(); i++) {
    audio[i] = std::sin(pitch * M_PI * 2.0 * i / freq)
      * std::numeric_limits<ALshort>::max();
  }

  // audio data creation
  HaeAudioData audio_data;
  audio_data
    .set_sampling_rate(freq)
    .set_format(AL_FORMAT_MONO16)
    .set_data(std::move(audio));

  Hae::bind_audio_to_buffer(audio_data);
  Hae::bind_buffer_to_source(audio_data);
  Hae::play_audio_from_source(audio_data.source_id());
  std::this_thread::sleep_for(std::chrono::seconds(2));

  Hae::kill_hae_context();
}