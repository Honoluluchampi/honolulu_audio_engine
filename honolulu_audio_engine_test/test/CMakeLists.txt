include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(run_test
        )

target_link_libraries(run_test gtest gtest_main)
target_link_libraries(run_test honolulu_audio_engine)