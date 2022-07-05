cmake_minimum_required(VERSION 3.16)

project(hae)

add_library(hae STATIC src/hae.cpp)

target_include_directories(hae PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        )

target_link_libraries(hae PUBLIC openal)