#include <hae.hpp>
#include <hae_audio_data.hpp>

namespace hae {

// define static members
std::queue<SourceId> Hae::pending_source_ids_;
ALCdevice*  Hae::device_ = nullptr;
ALCcontext* Hae::context_ = nullptr;

void Hae::start_hae_context()
{
  if (device_ || context_) return;
  // initialize openAL
  device_ = alcOpenDevice(nullptr);
  // TODO : configure context's attributes
  context_ = alcCreateContext(device_, nullptr);
  alcMakeContextCurrent(context_);

  // create pending sources
  SourceId sources[SOURCE_COUNT];
  alGenSources(SOURCE_COUNT, sources);
  for (const auto& source : sources) {
    pending_source_ids_.push(source);
  }
}

void Hae::kill_hae_context()
{
  // delete openAL resources
  alcMakeContextCurrent(nullptr);
  alcDestroyContext(context_);
  alcCloseDevice(device_);
}

Result Hae::bind_audio_to_buffer(HaeAudioData &audio_data)
{
  // generate buffer
  BufferId buffer_id;
  alGenBuffers(1, &buffer_id);

  // TODO : use try & catch to check alBufferData is successfully processed
  // copy the data to the buffer
  alBufferData(buffer_id,
               audio_data.format(),
               audio_data.data(),
               audio_data.data_size_in_byte(),
               audio_data.sampling_rate());

  // change audio_data's state
  audio_data.set_buffer_id(buffer_id);
  audio_data.set_is_bound_to_buffer(true);

  return Result::SUCCESS;
}

Result Hae::bind_buffer_to_source(HaeAudioData &audio_data)
{
  // check whether audio_data has a buffer
  if (!audio_data.is_bound_to_buffer()) return Result::FAILURE;
  // check whether there is a remaining pending source
  if (pending_source_ids_.empty()) return Result::FAILURE;

  // get source from pending_source
  auto source_id = pending_source_ids_.front();
  pending_source_ids_.pop();

  // bind buffer to source
  alSourcei(source_id, AL_BUFFER, audio_data.buffer_id());

  // change audio_data's state
  audio_data.set_source_id(source_id);
  audio_data.set_is_bound_to_source(true);

  return Result::SUCCESS;
}

Result Hae::remove_audio_resources(HaeAudioData& audio_data)
{
  // remove source
  if (audio_data.is_bound_to_source()) {
    remove_audio_from_source(audio_data);
  }

  // remove buffer
  if (audio_data.is_bound_to_buffer()) {
    auto buffer = audio_data.buffer_id();
    alDeleteBuffers(1, &buffer);
    audio_data.set_is_bound_to_buffer(false);
  }

  return Result::SUCCESS;
}

Result Hae::remove_audio_from_source(HaeAudioData& audio_data)
{
  // remove the audio from  the source
  alSourcei(audio_data.source_id(), AL_BUFFER, 0);

  // change the audio_data's state
  audio_data.set_is_bound_to_source(false);

  // make the source pending
  pending_source_ids_.push(audio_data.source_id());

  return Result::SUCCESS;
}

} // namespace hae