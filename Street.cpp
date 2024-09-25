//
// Created by imry on 9/24/24.
//

#include "Street.h"
#include <iostream>

// Method to build a house on the street
void Street::buildHouse() {
    if (hotel) {
        std::cerr << "Cannot build houses after a hotel has been built." << std::endl;
        return;
    }
    numHouses++;
    std::cout << "House built. Total houses: " << numHouses << std::endl;
    // Additional logic to increase rent or update street status can be added here
}

// Method to build a hotel on the street
void Street::buildHotel() {
    if (numHouses < 4) {
        std::cerr << "Need 4 houses before building a hotel." << std::endl;
        return;
    }
    hotel = true;
    std::cout << "Hotel built on the street." << std::endl;
    // Additional logic for hotel effects can be added here
}

// Method for when a player lands on the street
void Street::landOn(Player& player) {
    std::cout << player.getName() << " landed on " << getName() << std::endl;
    // Logic to handle rent payment, ownership check, etc.
    if (player != owner()) {
        std::cout << player.getName() << " owes rent of " << rent() << std::endl;
        // player.payRent(rent());  // Example, assuming player has a payRent method
    }
}

