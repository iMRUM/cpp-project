cmake_minimum_required(VERSION 3.29)
project(cpp)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(project
        model/Components/Board.h
        model/Components/Dice.h
        model/Components/Dice.cpp
        model/Components/Set_class/SetStreet.cpp
        model/Components/Set_class/SetRailroad.h
        controller/GameLogic.h
        controller/GameLogic.cpp
        model/Components/Set_class/Set.h
        model/Components/Square_class/Tradeable_class/Tradeable.cpp
        model/Constants.h
)
