// RollDiceCommand.cpp
#include "RollDiceCommand.hpp"
#include <iostream>
#include <cstdlib>  // For rand()



void RollDiceCommand::execute() {
    int die1 = (rand() % 6) + 1;  // Roll first die (1-6)
    int die2 = (rand() % 6) + 1;  // Roll second die (1-6)
    diceResult = die1 + die2;

    // Check for doubles
    doubleRoll = (die1 == die2);
    if (doubleRoll) {
        _player->incrementDoublesCount();
    } else {
        _player->resetDoublesCount();
    }
}

int RollDiceCommand::getDiceResult() const {
    return diceResult;
}

bool RollDiceCommand::isDouble() const {
    return doubleRoll;
}
