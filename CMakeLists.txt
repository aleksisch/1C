cmake_minimum_required(VERSION 3.15)
project(1C)

set(CMAKE_CXX_STANDARD 20)
include_directories(inc)

add_executable(1C src/main.cpp src/Decryptor.cpp)