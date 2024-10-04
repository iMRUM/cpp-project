//
// Created by imry on 10/4/24.
//

#ifndef GAMECONTROLLER_HPP
#define GAMECONTROLLER_HPP
#include "model/GameState.hpp"


class SpecialSquare;

class GameController {
private:
    GameState *gameState;

    void handle() {
        if (!isInJail()) {
            rollDice();
        } else {
            // u_3way_decision;
        }
    }

    bool isInJail() const {
        return gameState->getCurrentPlayer()->isInJail();
    }

    void rollDice(); // will call move
    void move(int steps) // wil call land on
    {
        gameState->getCurrentPlayer()->move(steps);
        landOnSquare(gameState->getCurrentPlayer()->getPosition());
    }

    void landOnSquare(int position){
        Square* s = gameState->getSquareAt(position);
        if(auto* _s = dynamic_cast<Tradeable*>(s)) {
            u_landOnTradeable(_s);
        }else {

            u_landOnSpecialSquare()
        }
        if (s->isTradeable()) {
            u_landOnTradeable(dynamic_cast<Tradeable*>(s));
        }

    }
    void u_landOnTradeable(Tradeable *tradeable); // player can buy, pay rent, or skip
    void _buyTradeable(Tradeable &tradeable);

    void _buildOnStreet(Street &street);

    void _payRent(Player &owner, int rent);

    void _skip();

    void u_landOnSpecialSquare(SpecialSquare *square);

    void _go2Jail(Player &player);

    void _payTax(Player &player);

    void bankrupt();

public:
    GameController(GameState *gameState): gameState(gameState) {
    }

    void start();
};


#endif //GAMECONTROLLER_HPP
