cmake_minimum_required(VERSION 3.20)
project(spsc_ring_buffer)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(spsc_ring_buffer
    src/main.cpp
)

target_include_directories(spsc_ring_buffer PRIVATE include)
