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
#include <set>
#include <unordered_set>
#include "Street.h"
#include "Tradeable.hpp"
using namespace std;
//Color set has a name, a _color and Tradeables
class Set {
private:
    int _color;
    string _color_name;
    unordered_set<unique_ptr<Tradeable>> _tradeables;

    // Helper function to ensure balanced house-building
    bool canBuildHouseOnStreet(Street* street, Player* owner) const;
public:
    Set(int color, const string& name, unordered_set<unique_ptr<Tradeable>> tradeables);

    // Check if the player owns all streets in this set
    bool isCompleteSetOwned(Player* owner) const;



    const string& getColorName() const;


};

#endif // COLOR_HPP

