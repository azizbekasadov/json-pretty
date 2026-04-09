cmake_minimum_required(VERSION 3.20)

project(json_pretty LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(json_pretty
     src/main.cpp
)

target_compile_features(json_pretty PRIVATE cxx_std_20)

target_compile_options(json_pretty PRIVATE 
    -Wall 
    -Wextra
    -Wpedantic
)

