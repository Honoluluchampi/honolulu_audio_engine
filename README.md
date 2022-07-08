# Honolulu Audio Engine

[![build_on_ubuntu](https://github.com/Honoluluchampi/honolulu_audio_engine/actions/workflows/build_on_ubuntu.yml/badge.svg)](https://github.com/Honoluluchampi/honolulu_audio_engine/actions/workflows/build_on_ubuntu.yml)
[![build_on_mac](https://github.com/Honoluluchampi/honolulu_audio_engine/actions/workflows/build_on_mac.yml/badge.svg)](https://github.com/Honoluluchampi/honolulu_audio_engine/actions/workflows/build_on_mac.yml)

## usage
- Audio data creation 
  - Take your audio data as `std::vector<ALshort>` or `std::array<ALshort, *>` and so on.
  - 
- Manage the index of your audios as `Hae::BufferId` by yourself, because your
audio will be assigned to a buffer through its id.
- Register your audio to Engine's buffer by specifying the buffer

<details><summary>sample</summary>

```c++

```

</details>

## functions

- void bind_audio_to_buffer(BufferId buffer_id, SourceId source_id, int freq, ALshort *data_ptr)
  
You should choose buffer_id of the sounds

## build (only tested in ubuntu20.04)
1. install libopenal-dev 
```shell
sudo apt install libopenal-dev
```
2. build by cmake
```shell
cd ${honolulu_audio_engine_directory}
mkdir build
cd build
cmake ..
make
```

## code convention
- snake_case : filename_name, variable_name, 
- CAPITAL_SNAKE_CASE : MACRO, CONSTANT
- CamelCase : ClassName
