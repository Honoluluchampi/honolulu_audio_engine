cmake_minimum_required(VERSION 3.16)

project(al VERSION 0.1.0)

add_executable(al src/main.cpp src/hae.cpp)

target_include_directories(al PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        )

target_link_libraries(al PUBLIC openal)