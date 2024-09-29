//
// Created by imry on 9/29/24.
//

#ifndef RAILROAD_H
#define RAILROAD_H
#include "SetUtility.h"
#include "Tradeable.hpp"


class Railroad: public Tradeable{
    public:
    Railroad(const std::string &name, const int price = 200, const int rent = 50, const Set &type_set = SetUtility(8, "Railroads")): Tradeable(name, price, rent, type_set){}
    // Copy Constructor (Rule of Three)
    Railroad(const Railroad &other) : Tradeable(other) {}

    // Copy Assignment Operator (Rule of Three)
    Railroad& operator=(const Railroad &other) {
        if (this != &other) {
            Tradeable::operator=(other);  // Call base class copy assignment
        }
        return *this;
    }
    // Destructor (Rule of Three)
    ~Railroad() override = default;
};



#endif //RAILROAD_H
