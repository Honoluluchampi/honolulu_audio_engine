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
    HaeAudioData()
    { static hae::BufferId i = 0; id_ = i++; }

    // setter (enable chain notation)
    HaeAudioData& set_format(const ALenum format) { format_ = format; return *this; }
    // complete transport std::vector<ALshort>
    template <typename T>
    HaeAudioData& set_data(T&& data);
    HaeAudioData& set_frequency(const ALsizei frequency) { frequency_ = frequency; return *this; }

    // getter
    const hae::BufferId buffer_id() const  { return id_; }
    const ALenum format() const { return format_; }
    const ALshort* data() const { return &data_[0]; }
    const ALsizei data_size_in_byte() const { return data_.size() * sizeof(ALshort); }
    const ALsizei frequency() const { return frequency_; }

  private:
    hae::BufferId id_;
    ALenum format_;
    std::vector<ALshort> data_;
    ALsizei frequency_;
};

template <typename T>
HaeAudioData& HaeAudioData::set_data(T&& data)
{
  data_ = std::forward<T>(data);
  return *this;
}

} // namespace hae