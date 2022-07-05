cmake_minimum_required(VERSION 3.16)

add_definitions(-std=c++20)

# build example
project(honolulu_audio_engine)
set(SOURCE_FILES example.cpp)
add_executable(honolulu_audio_engine ${SOURCE_FILES})
target_include_directories(honolulu_audio_engine PUBLIC include)
target_link_libraries(honolulu_audio_engine hae)

# build honolulu_audio_engine
project(hae)
add_library(hae STATIC src/hae.cpp)
target_include_directories(hae PUBLIC include)
target_link_libraries(hae PUBLIC openal)

# build test
project(test_run)
# enable google test
enable_testing()
# /find_package(GTest REQUIRED)
# /include(GoogleTest)
add_executable(test_run test/test.cpp)
target_link_directories(test_run PUBLIC ../build)
target_link_libraries(test_run hae gtest gtest_main)
gtest_discover_tests(test_run PROPERTIES TIMEOUT 600)
