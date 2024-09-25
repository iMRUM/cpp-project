cmake_minimum_required(VERSION 3.29)
project(cpp)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(cpp
        Board.cpp
        Board.h
    Game.cpp
    Game.h
        Property.cpp
        Property.h
        Square.cpp
        Street.cpp
        Street.h
        Railroad.cpp
        Railroad.h
        Utility.cpp
        Utility.h
        SpecialSquare.cpp
        SpecialSquare.h
        Player.cpp
        Player.h
        Dice.cpp
        Dice.h
        SquareFactory.cpp
        SquareFactory.h
        Constants.h
        Color.cpp
        Color.h)
