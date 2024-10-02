cmake_minimum_required(VERSION 3.29)
project(cpp)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(project
        model/Components/Board.h
        model/Components/Dice.h
        model/Components/Railroad.h
        model/Components/Board.cpp
        model/Components/Dice.cpp
        model/Components/Player.cpp
        model/Components/Railroad.cpp
        model/Components/SetStreet.cpp
        model/Components/SetRailroad.h
        controller/GameLogic.h
        controller/GameLogic.cpp
        model/Components/SetTradeable.hpp
)
