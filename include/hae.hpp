#pragma once

// std
#include <queue>
#include <unordered_map>
#include <memory>

// openAL
#include <AL/al.h>
#include <AL/alc.h>

// engine
namespace hae {

// forward declaration
class HaeAudioData;

using BufferId = ALuint;
using SourceId = ALuint;

constexpr size_t BUFFER_COUNT = 8;
constexpr size_t SOURCE_COUNT = 4;

// represents hae process's result state
enum class Result
{
  SUCCESS, FAILURE
};

class Hae
{
  public:
    Hae();
    ~Hae();

    static Result bind_audio_to_buffer(HaeAudioData &audio_data);
    static Result bind_buffer_to_source(HaeAudioData &audio_data);

    // getter
    static size_t remaining_pending_sources_count() { return pending_source_ids_.size(); }

  private:
    // openAL resources
    static std::queue<SourceId> pending_source_ids_;

    ALCdevice *device_;
    ALCcontext *context_;
};
} // namespace hae