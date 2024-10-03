//
// Created by imry on 9/29/24.
//

#ifndef MOVECOMMAND_HPP
#define MOVECOMMAND_HPP
#include "AbstractCommand.hpp"



class MoveCommand: public AbstractCommand{
    private:
    int _steps;
    public:
    MoveCommand(): _steps(0) {
    }

    MoveCommand(Player* player, int steps) : AbstractCommand(player), _steps(steps) {
}

~MoveCommand() override;

void execute() override {
    _player->move(_steps);
}
};



#endif //MOVECOMMAND_HPP
