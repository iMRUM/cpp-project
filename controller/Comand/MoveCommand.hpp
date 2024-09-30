//
// Created by imry on 9/29/24.
//

#ifndef MOVECOMMAND_HPP
#define MOVECOMMAND_HPP
#include "AbstractCommand.hpp"
#include "Player.h"


class MoveCommand: public AbstractCommand{
int _steps;
    public:
    MoveCommand(int steps) : _steps(steps) {}

~MoveCommand() override;

void execute(Player &player) override {
    player.move(_steps);
}
};



#endif //MOVECOMMAND_HPP
