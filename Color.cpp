//
// Created by imry on 9/24/24.
//

#include "Color.h"


Color::Color(const std::string& name) : colorName(name) {}

void Color::addStreet(Street* street) {
    streets.push_back(street);
}

bool Color::isCompleteSetOwned(Player* owner) const {
    // Check if the player owns all the streets in this color group
    for (const Street* street : streets) {
        if (street->getOwner() != owner) {
            return false;
        }
    }
    return true;
}

void Color::buildHouseOnStreet(Street* street, Player* owner) {
    if (!isCompleteSetOwned(owner)) {
        throw std::logic_error("Player does not own the complete color set.");
    }

    if (!canBuildHouseOnStreet(street, owner)) {
        throw std::logic_error("Cannot build more houses on this street.");
    }

    street->buildHouse();
    std::cout << "House built on " << street->getName() << " in color group " << colorName << "\n";
}

const std::vector<Street*>& Color::getStreets() const {
    return streets;
}

const std::string& Color::getColorName() const {
