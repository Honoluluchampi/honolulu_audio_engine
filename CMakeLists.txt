cmake_minimum_required(VERSION 3.16)

project(honolulu_audio_engine)

add_definitions(-std=c++20)

set(SOURCE_FILES main.cpp)
add_executable(honolulu_audio_engine_run ${SOURCE_FILES})

include_directories(honolulu_audio_engine)

add_subdirectory(honolulu_audio_engine)
add_subdirectory(honolulu_audio_engine_test)

target_link_libraries(honolulu_audio_engine_run honolulu_audio_engine)