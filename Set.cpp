//
// Created by imry on 9/24/24.
//

#include "Set.h"


Set::Set(const std::string& name) : colorName(name) {}

void Set::addStreet(Street* street) {
    streets.push_back(street);
}

bool Set::isCompleteSetOwned(Player* owner) const {
    // Check if the player owns all the streets in this color group
    for (const Street* street : streets) {
        if (street->getOwner() != *owner) {
            return false;
        }
    }
    return true;
}

void Set::buildHouseOnStreet(Street* street, Player* owner) {
    if (!isCompleteSetOwned(owner)) {
        throw std::logic_error("Player does not own the complete color set.");
    }

    if (!canBuildHouseOnStreet(street, owner)) {
        throw std::logic_error("Cannot build more houses on this street.");
    }

    street->buildHouse();
    std::cout << "House built on " << street->getName() << " in color group " << colorName << "\n";
}

const std::vector<Street*>& Set::getStreets() const {
    return streets;
}

const std::string& Set::getColorName() const {
