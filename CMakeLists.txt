cmake_minimum_required(VERSION 3.16)

add_definitions(-std=c++2a)

# for OS X
if (APPLE)
    # search brew's root
    execute_process(
            COMMAND brew --prefix
            RESULT_VARIABLE BREW
            OUTPUT_VARIABLE BREW_PREFIX
            OUTPUT_STRIP_TRAILING_WHITESPACE
    )
    execute_process(
            COMMAND ls ${BREW_PREFIX}/Cellar/openal-soft
            RESULT_VARIABLE OPEN_AL
            OUTPUT_VARIABLE OPEN_AL_VERSION
            OUTPUT_STRIP_TRAILING_WHITESPACE
    )
    execute_process(
            COMMAND ls ${BREW_PREFIX}/Cellar/googletest
            RESULT_VARIABLE GOOGLE_TEST
            OUTPUT_VARIABLE GOOGLE_TEST_VERSION
            OUTPUT_STRIP_TRAILING_WHITESPACE
    )
    set(OPEN_AL_DIRECTORY ${BREW_PREFIX}/Cellar/openal-soft/${OPEN_AL_VERSION})
    set(GOOGLE_TEST_DIRECTORY ${BREW_PREFIX}/Cellar/googletest/${GOOGLE_TEST_VERSION})
endif (APPLE)

# build example
project(sample)
set(SOURCE_FILES sample.cpp)
add_executable(sample ${SOURCE_FILES})
if (APPLE)
    target_include_directories(sample PUBLIC include
            # openAL
            ${OPEN_AL_DIRECTORY}/include)
elseif (UNIX)
    target_include_directories(sample PUBLIC include)
endif (APPLE)
target_link_libraries(sample hae)

# build honolulu_audio_engine
project(hae)
add_library(hae STATIC src/hae.cpp)
if (APPLE)
    target_include_directories(hae PUBLIC include
            # openAL
            ${OPEN_AL_DIRECTORY}/include)
elseif (UNIX)
    target_include_directories(hae PUBLIC include)
endif (APPLE)
# openAL
if (APPLE)
    target_link_directories(hae PUBLIC ${OPEN_AL_DIRECTORY}/lib)
endif (APPLE)
target_link_libraries(hae PUBLIC openal)

# build test
project(test_run)
# enable google test
enable_testing()
add_executable(test_run test/hae_test.cpp test/hae_audio_data_test.cpp)
# to link hae
if (APPLE)
    target_include_directories(test_run PUBLIC
            # googletest
            ${GOOGLE_TEST_DIRECTORY}/include)
    target_link_directories(test_run PUBLIC build
            # googletest
            ${GOOGLE_TEST_DIRECTORY}/lib)
elseif (UNIX)
    target_link_directories(test_run PUBLIC build)
endif (APPLE)
target_link_libraries(test_run hae gtest gtest_main pthread)