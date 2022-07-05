#pragma once

// openAL
#include <AL/al.h>
#include <AL/alc.h>

// std
#include <vector>
#include <memory>

// honolulu_audio_engine
namespace hae {

class Hae
{
  public:
    using BufferId = size_t;
    using SourceId = size_t;

    Hae();

    void register_monaural_audio
    (BufferId buffer_id, SourceId source_id, int freq, ALshort *data_ptr);

    void register_stereo_audio
    (BufferId buffer_id, SourceId source_id, int freq, ALshort *right_data_ptr, ALshort *left_data_ptr);

  private:
    // openAL resources
    std::vector<ALuint> buffer_ids_;
    std::vector<ALuint> source_ids_;

    ALCdevice *device_;
    ALCcontext *context_;
};
} // namespace hae