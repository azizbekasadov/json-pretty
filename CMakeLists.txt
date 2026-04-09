cmake_minimum_required(VERSION 3.20)

project(json_pretty LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(json_pretty_core 
    src/parser.cpp
)

target_include_directories(json_pretty_core
    PUBLIC 
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_executable(json_pretty
    cli/main.cpp
)

target_link_libraries(json_pretty
    PRIVATE json_pretty_core
)

target_compile_features(json_pretty PRIVATE cxx_std_20)

target_compile_options(json_pretty PRIVATE 
    -Wall 
    -Wextra
    -Wpedantic
)

