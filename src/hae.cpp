#include "hae.hpp"
#include "hae_audio_data.hpp"

// std
#include <cassert>

namespace hae {

Hae::Hae()
{
  // initialize openAL
  device_ = alcOpenDevice(nullptr);
  // TODO : configure context's attributes
  context_ = alcCreateContext(device_, nullptr);
  alcMakeContextCurrent(context_);
}

void Hae::bind_audio_to_buffer(const HaeAudioData &audio_data)
{
  auto buffer_id = audio_data.buffer_id();
  // adjust buffer count
  if (buffer_id >= buffer_ids_.size())
    // TODO : configure allocation count e.g. buffer_id * 2
    buffer_ids_.resize(buffer_id * 2);

  // create buffer
  alGenBuffers(1, &buffer_ids_[buffer_id]);

  // copy the data to the buffer
  alBufferData(buffer_id,
               audio_data.format(),
               audio_data.data(),
               audio_data.data_size_in_byte(),
               audio_data.sampling_rate());
}

void Hae::register_stereo_audio(const HaeAudioData &audio_data)
{

}

} // namespace hae