//
// Created by imry on 9/29/24.
//

#ifndef BUYCOMMAND_HPP
#define BUYCOMMAND_HPP
#include "AbstractCommand.hpp"

class BuyCommand: public AbstractCommand{
    Tradeable* tradeable;
    bool _valid_payment() const {
        return _player->getBalance()>tradeable->getPrice();
    }
public:
    BuyCommand(): tradeable(nullptr) {
    }

    BuyCommand(Player* player, Tradeable* tradeable) : AbstractCommand(player), tradeable(tradeable) {}

    ~BuyCommand() override;

    void execute() override {
        if (_valid_payment()) {
            tradeable->buy(_player);
            _player->pay(tradeable->getPrice());
        }
    }
};
#endif //BUYCOMMAND_HPP
