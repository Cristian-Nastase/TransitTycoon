cmake_minimum_required(VERSION 4.1)
project(TransitTycoon CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

add_executable(TransitTycoon
        src/main.cpp
        include/exceptions/GameExceptions.h
        include/core/RandomGenerator.h
        src/core/RandomGenerator.cpp
        include/core/ConfigLoader.h
        src/core/ConfigLoader.cpp
        include/patterns/IObserver.h
        include/patterns/ISubject.h
        include/core/WeatherSystem.h
        src/core/WeatherSystem.cpp
        include/transport/TransportMode.h
        src/transport/TransportMode.cpp
        include/transport/Metro.h
        src/transport/Metro.cpp
        include/transport/Tram.h
        src/transport/Tram.cpp
        include/transport/Bus.h
        src/transport/Bus.cpp
        include/transport/Walking.h
        src/transport/Walking.cpp
        include/templates/Repository.h
        include/patterns/ChoiceStrategy.h
        include/people/Person.h
        src/people/Person.cpp
        include/patterns/WeightedRandomStrategy.h
        src/patterns/WeightedRandomStrategy.cpp
        include/patterns/CheapestStrategy.h
        src/patterns/CheapestStrategy.cpp
        include/people/PersonFactory.h
        src/people/PersonFactory.cpp
        include/upgrades/Upgrade.h
        src/upgrades/Upgrade.cpp
        include/upgrades/UmbrellaUpgrade.h
        src/upgrades/UmbrellaUpgrade.cpp
        include/upgrades/CapacityUpgrade.h
        src/upgrades/CapacityUpgrade.cpp
        include/upgrades/HappinessUpgrade.h
        src/upgrades/HappinessUpgrade.cpp
        include/upgrades/DiscountUpgrade.h
        src/upgrades/DiscountUpgrade.cpp
        include/upgrades/UpgradeFactory.h
        src/upgrades/UpgradeFactory.cpp
        include/core/RoundResult.h
        src/core/RoundResult.cpp
        include/core/Game.h
        src/core/Game.cpp
        include/ui/ConsoleUI.h
        src/ui/ConsoleUI.cpp
)

target_include_directories(TransitTycoon PRIVATE include)

file(COPY ${CMAKE_SOURCE_DIR}/data DESTINATION ${CMAKE_BINARY_DIR})