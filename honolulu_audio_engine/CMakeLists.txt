project(al VERSION 0.1.0)

add_executable(al ../main.cpp src/hae.cpp)

target_include_directories(al PUBLIC
        include
        )

target_link_libraries(al PUBLIC openal)