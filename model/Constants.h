//
// Created by imry on 9/24/24.
//

#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

#include <SFML/Graphics.hpp>  // for sf::Set

#include "Components/Set_class/SetRailroad.h"
#include "Components/Set_class/SetStreet.h"
#include "model/Components/Square_class/Square.h"

namespace Constants {
    // Colors for different sets
    const sf::Color BROWN = sf::Color(139, 69, 19);
    const sf::Color LIGHT_BLUE = sf::Color(173, 216, 230);
    const sf::Color PINK = sf::Color(255, 192, 203);
    const sf::Color ORANGE = sf::Color(255, 165, 0);
    const sf::Color RED = sf::Color(255, 0, 0);
    const sf::Color YELLOW = sf::Color(255, 255, 0);
    const sf::Color GREEN = sf::Color(0, 128, 0);
    const sf::Color DARK_BLUE = sf::Color(0, 0, 255);

    // Types of squares
    enum SquareType {
        STREET,
        RAILROAD,
        UTILITY,
        SPECIAL
    };
    // Sets
    shared_ptr<SetStreet> STREET_SET(new SetStreet(SquareType::STREET, "street"));
    shared_ptr<SetRailroad> RAILROAD_SET(new SetRailroad(SquareType::RAILROAD, "railroad"));
    shared_ptr<Set> UTILITY_SET(new Set(SquareType::UTILITY, "utility"));

    const Set SPECIAL_SET = Set(SquareType::SPECIAL, "special");
    const std::vector<Square*> SBOARD(40, nullptr);
    // Define other game constants
    const int INITIAL_PLAYER_MONEY = 1500;
    const int PASS_GO_MONEY = 200;
    const int JAIL_FINE = 50;

    // Rent rates for railroads
    const int RAILROAD_RENT[4] = {50, 100, 150, 200};
}

#endif // CONSTANTS_HPP

