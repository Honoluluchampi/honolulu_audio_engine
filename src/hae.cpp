#include <hae.hpp>

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

void Hae::register_monaural_audio
(BufferId buffer_id, SourceId source_id, int freq, ALshort *data_ptr)
{
  // adjust buffer count
  if (buffer_id >= buffer_ids_.size())
    // TODO : configure allocation count e.g. buffer_id * 2
    buffer_ids_.resize(buffer_id);

  // create buffer
  alGenBuffers(1, &buffer_ids_[buffer_id]);
}

void Hae::register_stereo_audio
(BufferId id, SourceId source, int freq, ALshort *right_data_ptr, ALshort *left_data_ptr)
{

}

} // namespace hae