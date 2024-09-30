//
// Created by imry on 9/29/24.
//

#ifndef BUYCOMMAND_HPP
#define BUYCOMMAND_HPP
#include "AbstractCommand.hpp"

class BuyCommand: public AbstractCommand{
    void* field;
public:
    BuyCommand(int steps) : _steps(steps) {}

    ~BuyCommand() override;

    void execute(Player &player) override {
        player._(_field);
    }
};
#endif //BUYCOMMAND_HPP
