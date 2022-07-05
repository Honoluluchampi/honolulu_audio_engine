project(test_run)

cmake_minimum_required(VERSION 3.16)

# enable the testing features
enable_testing()

# enable google test
find_package(GTest REQUIRED)
include(GoogleTest)

add_executable(test_run
        src/test.cpp)

target_link_directories(test_run PUBLIC ../engine/build)
target_link_libraries(test_run hae GTest::GTest GTest::Main)

gtest_discover_tests(test_run)
