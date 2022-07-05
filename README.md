# Honolulu Audio Engine

## usage
- You have to manage the index of audios as `Hae::BufferId` type.

<details><summary>sample</summary>

```c++

```

<detalis>

## functions

- void register_monaural_audio(BufferId buffer_id, SourceId source_id, int freq, ALshort *data_ptr)
  
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