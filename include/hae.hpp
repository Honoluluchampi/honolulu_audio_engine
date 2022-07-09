#pragma once

// std
#include <queue>
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

    // audio process functions
    static Result bind_audio_to_buffer(HaeAudioData& audio_data);
    static Result bind_buffer_to_source(HaeAudioData& audio_data);
    static Result remove_audio_resources(HaeAudioData& audio_data);
    static Result remove_audio_from_source(HaeAudioData& audio_data);
    inline static void play_audio_from_source(SourceId source_id);
    inline static void stop_audio_from_source(SourceId source_id);

    // getter
    static size_t remaining_pending_sources_count() { return pending_source_ids_.size(); }

  private:
    // openAL resources
    static std::queue<SourceId> pending_source_ids_;

    ALCdevice* device_;
    ALCcontext* context_;
};
} // namespace hae