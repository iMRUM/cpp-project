cmake_minimum_required(VERSION 3.29)
project(cpp)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(cpp
        Board.cpp
        Board.h
        GameLogic/GameLogic.cpp
        GameLogic/GameLogic.h
        Components/Street.cpp
        Components/Street.h
        Player.cpp
        Player.h
        Dice.cpp
        Dice.h
        SquareFactory.cpp
        SquareFactory.h
        Constants.h
        Set.cpp
        Set.h
        Components/Tradeable.cpp
        Components/Tradeable.hpp
        SetStreet.cpp
        SetStreet.h
        SetUtility.cpp
        SetUtility.h
        Components/Railroad.cpp
        Components/Railroad.h
        Components/Utility.cpp
        Components/Utility.h
        Components/Square.h
        Components/SpecialSquare.cpp
        Components/SpecialSquare.h
        States/State.h
        States/JailState.cpp
        States/JailState.h
        States/NormalState.cpp
        States/NormalState.h
        controller/Comand/AbstractCommand.hpp
        controller/Comand/MoveCommand.hpp
        controller/Comand/BuyCommand.hpp
        UI/GeneralUI.hpp
        UI/PlayerUI.hpp
        controller/Comand/Pay2PeerCommand.hpp
        controller/Comand/RollDiceCommand.hpp
        controller/GameController.hpp)
