//
// Created by imry on 9/29/24.
//

#ifndef UTILITY_H
#define UTILITY_H
#include "SetUtility.h"
#include "Tradeable.hpp"


class Utility: public Tradeable{
    Utility(const std::string &name, const int price = 150, const int rent = 10, const Set &type_set = SetUtility(9, "Utility Companies")): Tradeable(name, price, rent, type_set){}

    // Copy Constructor (Rule of Three)
    Utility(const Utility &other) : Tradeable(other) {}

    // Copy Assignment Operator (Rule of Three)
    Utility& operator=(const Utility &other) {
        if (this != &other) {
            Tradeable::operator=(other);  // Call base class copy assignment
        }
        return *this;
    }
    // Destructor (Rule of Three)
    ~Utility() override = default;

};



#endif //UTILITY_H
