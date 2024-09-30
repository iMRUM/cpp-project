//
// Created by imry on 9/24/24.
//

#include "Street.h"
#include <iostream>

// Method to build a house on the street
void Street::buildHouse() {
    if (hotel) { // should be deprecated
        std::cerr << "Cannot build houses after a hotel has been built." << std::endl;
        return;
    }
    if (houses>0){set_rent(rent()*2);}
    houses++;
    std::cout << "House built. Total houses: " << houses << std::endl;
}

// Method to build a hotel on the street
void Street::buildHotel() {
    if (houses < 4) { // should be deprecated
        std::cerr << "Need 4 houses before building a hotel." << std::endl;
        return;
    }
    set_rent(rent()*3);
    hotel = true;
    std::cout << "Hotel built on the street." << std::endl;
}

// Method for when a player lands on the street
int Street::landOn(Player *player) {
    std::cout << player->name() << " landed on " << name() << std::endl;
    // Logic to handle rent payment, ownership check, etc.
    if (*player != owner()) {
        std::cout << player->name() << " owes rent of " << rent() << std::endl;
    }
}

