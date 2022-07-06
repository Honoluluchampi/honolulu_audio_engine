#pragma once

// openAL
#include <AL/al.h>
#include <AL/alc.h>

namespace hae {

// BufferId / SourceId is not same as ALuint
using BufferId = size_t;
using SourceId = size_t;

class HaeAudioData
{
  public:
    // default is sampling rate = 44100, format is AL_FORMAT_MONO16
    HaeAudioData(ALsizei sampling_rate = 44100, ALenum format = AL_FORMAT_MONO16)
      : sampling_rate_(sampling_rate), format_(format)
    {
      static hae::BufferId i = 0;
      id_ = i++;
    }

    // setter (enable chain notation)
    HaeAudioData &set_format(const ALenum format)
    {
      format_ = format;
      return *this;
    }

    // complete transport std::vector<ALshort>
    template<typename T>
    HaeAudioData &set_data(T &&data);

    HaeAudioData &set_sampling_rate(const ALsizei frequency)
    {
      sampling_rate_ = frequency;
      return *this;
    }

    // getter
    const BufferId buffer_id() const { return id_; }

    const ALenum format() const { return format_; }

    const ALshort *data() const { return &data_[0]; }

    const ALsizei data_size_in_byte() const { return data_.size() * sizeof(ALshort); }

    const ALsizei sampling_rate() const { return sampling_rate_; }

  private:
    hae::BufferId id_;
    ALenum format_;
    std::vector<ALshort> data_;
    ALsizei sampling_rate_;
};

template<typename T>
HaeAudioData &HaeAudioData::set_data(T &&data)
{
  data_ = std::forward<T>(data);
  return *this;
}

} // namespace hae