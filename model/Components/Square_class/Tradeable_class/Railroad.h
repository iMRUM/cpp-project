//
// Created by imry on 9/29/24.
//

#ifndef RAILROAD_H
#define RAILROAD_H
#include "SetRailroad.h"
#include "Tradeable.hpp"


class Railroad: public Tradeable{
    public:
    Railroad(const std::string &name, const int price = 200, const int rent = 50): Tradeable(name, price, rent, type_set) {

    }
    // Copy Constructor (Rule of Three)
    Railroad(const Railroad &other) : Railroad(other.getName(), other.getPrice(), other.getRent()) {}

    // Copy Assignment Operator (Rule of Three)
    Railroad& operator=(const Railroad& other) {
        if (this != &other) {
            setName(other.getName());
            setPrice(other.getPrice());
            setRent(other.getRent());
            set_type(other.getType());
        }
        return *this;
    }
    // Destructor (Rule of Three)
    ~Railroad() = default;

};



#endif //RAILROAD_H
