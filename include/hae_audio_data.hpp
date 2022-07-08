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
    explicit HaeAudioData(ALenum format = AL_FORMAT_MONO16, unsigned int sampling_rate = 44100)
      : format_(format), sampling_rate_(sampling_rate)
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

    HaeAudioData &set_sampling_rate(const unsigned int sampling_rate)
    {
      sampling_rate_ = sampling_rate;
      return *this;
    }

    // getter
    const hae::BufferId buffer_id() const { return id_; }

    const ALenum format() const { return format_; }

    const ALshort *data() const { return &data_[0]; }

    const ALsizei data_size_in_byte() const { return data_.size() * sizeof(ALshort); }

    const unsigned int sampling_rate() const { return sampling_rate_; }

  private:
    hae::BufferId id_;
    ALenum format_;
    std::vector<ALshort> data_;
    unsigned int sampling_rate_;
};

template<typename T>
HaeAudioData &HaeAudioData::set_data(T &&data)
{
  data_ = std::forward<T>(data);
  return *this;
}

} // namespace hae