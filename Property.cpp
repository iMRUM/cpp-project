//
// Created by imry on 9/24/24.
//

#include "Property.h"

Property::Property(const std::string &name, int price, int rent): Square(name), _price(price), _rent(rent) {
}

void Property::setOwner(Player *owner) {
    this->_owner = owner;
}

Player * Property::getOwner() const {
    return this->_owner;
}

void Property::landOn(Player &player) {
}

int Property::getPrice() const {
    return this->_price;
}

int Property::getRent() const {
    return this->_rent;
}
