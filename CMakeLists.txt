cmake_minimum_required(VERSION 4.1)
project(TransitTycoon CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

add_executable(TransitTycoon
        src/main.cpp
)

target_include_directories(TransitTycoon PRIVATE include)

file(COPY ${CMAKE_SOURCE_DIR}/data DESTINATION ${CMAKE_BINARY_DIR})