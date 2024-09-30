//
// Created by rodki on 25/09/2024.
//

#include "Tradeable.hpp"

int Tradeable::landOn(Player* player) { // returns negative number if owned by player, 0 if empty, or the amount of rent to be payed.
    if(hasOwner()) {
        if (player == owner()) {
            return -1;
        }
        return rent();
    }
    return 0;
}

void Tradeable::buy(Player *player) {
    set_owner(player);
}


