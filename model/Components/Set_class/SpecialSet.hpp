//
// Created by imry on 10/2/24.
//

#ifndef SPECIALSET_HPP
#define SPECIALSET_HPP
#include "Set.h"


class SpecialSet: public Set {
public:
    SpecialSet(const int color, const string &name): Set(color, name) {}

    ~SpecialSet() override = default;

    SpecialSet(const SpecialSet &other)
        : SpecialSet(other.getColor(), other.getColorName()) {
    }

    SpecialSet & operator=(const SpecialSet &other) {
        if (this != &other) {
            setColor(other.getColor());
            setColorName(other.getColorName());
        }
        return *this;
    }
};



#endif //SPECIALSET_HPP
