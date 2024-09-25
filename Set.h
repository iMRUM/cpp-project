//
// Created by imry on 9/24/24.
//

#ifndef COLOR_HPP
#define COLOR_HPP

#include <vector>
#include <string>
#include <stdexcept>
#include <algorithm>
#include <iostream>
#include "Street.h"
// Set has Streets
class Set {
public:
    Set(const std::string& name);

    // Add a street to this color set
    void addStreet(Street* street);

    // Check if the player owns all streets in this set
    bool isCompleteSetOwned(Player* owner) const;

    // Build houses on a street in this color group (ensuring even build)
    void buildHouseOnStreet(Street* street, Player* owner);

    // Get all streets in the color group
    const std::vector<Street*>& getStreets() const;

    const std::string& getColorName() const;

private:
    std::string colorName;
    std::vector<Street*> streets;

    // Helper function to ensure balanced house-building
    bool canBuildHouseOnStreet(Street* street, Player* owner) const;
};

#endif // COLOR_HPP

