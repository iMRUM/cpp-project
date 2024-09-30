cmake_minimum_required(VERSION 3.29)
project(cpp)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(cpp
        controller/SquareFactory.h
        model/Board.cpp
        model/Constants.h
        model/Dice.h
        model/GameLogic.h
        model/Railroad.h)
