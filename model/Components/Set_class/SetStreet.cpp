//
// Created by imry on 9/29/24.
//

#include "SetStreet.h"
bool SetStreet::canBuildHouseOnStreet(Street* street, Player* owner) const {
    if(isCompleteSetOwned(owner) >= 0) {
        return false;
    }
    for (const auto& _street : _streets) {
        // If the number of houses is different, return false
        if (_street->getNumHouses() != street->getNumHouses()) {
            return false;
        }
    }
    return true;
}
int SetStreet::isCompleteSetOwned(Player *owner) const { // returns number of owned _streets, if set is owned returns -1.
    // Check if the player owns all the _streets in this set
    int i = 0;
    for (const auto& street : _streets) {
        if (street->getOwner() == owner) {
            i++;
        }
    }
    if (i==_streets.size()) {
        i = -1;
    }
    return i;
}
