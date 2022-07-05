cmake_minimum_required(VERSION 3.16)

project(honolulu_audio_engine)

add_definitions(-std=c++20)

set(SOURCE_FILES example.cpp)
add_executable(honolulu_audio_engine ${SOURCE_FILES})

target_include_directories(honolulu_audio_engine PUBLIC engine/include)

add_subdirectory(engine)
add_subdirectory(test)

target_link_libraries(honolulu_audio_engine hae)