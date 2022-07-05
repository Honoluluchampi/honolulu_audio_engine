#pragma once

// std
#include <vector>
#include <memory>

// openAL
#include <AL/al.h>
#include <AL/alc.h>

// engine
namespace hae {

// forward declaration
class HaeAudioData;

class Hae
{
  public:
    Hae();

    void bind_audio_to_buffer(const HaeAudioData& audio_data);

    void register_stereo_audio(const HaeAudioData& audio_data);

  private:
    // openAL resources
    std::vector<ALuint> buffer_ids_;
    std::vector<ALuint> source_ids_;

    ALCdevice *device_;
    ALCcontext *context_;
};
} // namespace hae