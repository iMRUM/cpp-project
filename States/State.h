//
// Created by imry on 9/29/24.
//

#ifndef STATE_H
#define STATE_H
#include "Player.h"


class State {
public:
    virtual ~State() =default;
    virtual void rollDice(Player& player) = 0;


};



#endif //STATE_H
