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
//Color set has a getName, a _color
class Set {
private:
    int _color;
    string _color_name;



public:
    Set(int color, const string& name);
    virtual ~Set();


    const string& getColorName() const;


};

#endif // COLOR_HPP

