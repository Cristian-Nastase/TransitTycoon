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
        include/exceptions/GameExceptions.h
        include/core/RandomGenerator.h
        include/core/RandomGenerator.cpp
        include/core/ConfigLoader.h
        include/core/ConfigLoader.cpp
        include/patterns/IObserver.h
        include/patterns/ISubject.h
        include/core/WeatherSystem.h
        include/core/WeatherSystem.cpp
        include/transport/TransportMode.h
        include/transport/TransportMode.cpp
        include/transport/Metro.h
        include/transport/Metro.cpp
        include/transport/Tram.h
        include/transport/Tram.cpp
        include/transport/Bus.h
        include/transport/Bus.cpp
        include/transport/Walking.h
        include/transport/Walking.cpp
)

target_include_directories(TransitTycoon PRIVATE include)

file(COPY ${CMAKE_SOURCE_DIR}/data DESTINATION ${CMAKE_BINARY_DIR})