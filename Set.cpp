//
// Created by imry on 9/24/24.
//

#include "Set.h"


Set::Set(int color, const std::string &name, std::unordered_set<std::unique_ptr<Tradeable>> tradeable_unique_ptrs): _color_name(name), _color(color), _tradeables(tradeables) {
}
bool Set::canBuildHouseOnStreet(Street* street, Player* owner) const {
    for (const auto& tradeable : _tradeables) {
        // Attempt to cast tradeable to Street*
        Street* tempStreet = dynamic_cast<Street*>(tradeable.get());
        // If the tradeable is not a Street or the number of houses is different, return false
        if (tempStreet->getNumHouses() != street->getNumHouses()) {
            return false;
        }
    }
    return true;
}



bool Set::isCompleteSetOwned(Player* owner) const {
    // Check if the player owns all the streets in this _color group
    for (unique_ptr<Tradeable> tradeable : _tradeables) {
        if (tradeable->owner() != *owner) {
            return false;
        }
    }
    return true;
}



const std::string& Set::getColorName() const {
    return _color_name;
}
