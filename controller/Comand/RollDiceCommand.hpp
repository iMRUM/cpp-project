// RollDiceCommand.hpp
#pragma once
#include "AbstractCommand.hpp"
#include "AbstractCommand.hpp"
#include "../../model/Components/Player.h"

class RollDiceCommand : public AbstractCommand {
public:
    RollDiceCommand(): diceResult(0), doubleRoll(false) {
    }

    RollDiceCommand(Player* player): AbstractCommand(player), diceResult(0), doubleRoll(false) {

    }

    void execute() override;
    int getDiceResult() const;
    bool isDouble() const;

private:
    int diceResult;
    bool doubleRoll;

    int rollDice();
};
