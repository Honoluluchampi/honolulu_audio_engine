#pragma once

// openAL
#include <AL/al.h>
#include <AL/alc.h>

namespace hae {

using BufferId = ALuint;
using SourceId = ALuint;

class HaeAudioData
{
  public:
    explicit HaeAudioData(ALenum format = AL_FORMAT_MONO16, ALsizei sampling_rate = 44100)
      : format_(format), sampling_rate_(sampling_rate)
    {
      static hae::BufferId i = 0;
      buffer_id_ = i++;
    }

    // setter (enable chain notation)
    // complete transport std::vector<ALshort>
    template<typename T>
    HaeAudioData &set_data(T &&data)
    {
      data_ = std::forward<T>(data);
      return *this;
    }
    HaeAudioData &set_format(const ALenum format)
    {
      format_ = format;
      return *this;
    }
    HaeAudioData &set_sampling_rate(const ALsizei sampling_rate)
    {
      sampling_rate_ = sampling_rate;
      return *this;
    }
    void set_buffer_id(BufferId id) { buffer_id_ = id; }
    void set_source_id(SourceId id) { source_id_ = id; }
    void set_bound_to_buffer(bool state) { is_bound_to_buffer_ = state; }
    void set_bound_to_source(bool state) { is_bound_to_source_ = state; }

    // getter
    [[nodiscard]] const ALshort *data() const { return &data_[0]; }
    [[nodiscard]] BufferId buffer_id() const { return buffer_id_; }
    [[nodiscard]] bool is_bound_to_buffer() const { return is_bound_to_buffer_; }
    [[nodiscard]] SourceId source_id() const { return source_id_; }
    [[nodiscard]] bool is_bound_to_source() const { return is_bound_to_source_; }
    [[nodiscard]] ALenum format() const { return format_; }
    [[nodiscard]] ALsizei data_size_in_byte() const { return data_.size() * sizeof(ALshort); }
    [[nodiscard]] ALsizei sampling_rate() const { return sampling_rate_; }

  private:
    BufferId buffer_id_;
    bool is_bound_to_buffer_;
    SourceId source_id_;
    bool is_bound_to_source_;

    ALenum format_;
    std::vector<ALshort> data_;
    ALsizei sampling_rate_;
};
} // namespace hae