//
// Created by imry on 10/3/24.
//

#ifndef LANDONCOMMAND_HPP
#define LANDONCOMMAND_HPP
#include "AbstractCommand.hpp"


class LandOnTradeableCommand :public AbstractCommand{
    int _case;
    Tradeable* square;

    public:
    LandOnTradeableCommand(Player* player, Tradeable* square): AbstractCommand(player), _case(3), square(square) {
    }

    void execute() override {
        _case = square->landOn(_player);
    }
    int getCase() const {
        return _case;
    }
};



#endif //LANDONCOMMAND_HPP
