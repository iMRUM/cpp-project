//
// Created by imry on 9/29/24.
//

#ifndef SETUTILITY_H
#define SETUTILITY_H
#include "Set.h"


class SetRailroad: public Set {
public:
    SetRailroad(const int color, const string &name): Set(color, name) {}

    ~SetRailroad() override = default;

    SetRailroad(const SetRailroad &other)
        : SetRailroad(other.getColor(), other.getColorName()) {
    }

    SetRailroad & operator=(const SetRailroad &other) {
        if (this != &other) {
            setColor(other.getColor());
            setColorName(other.getColorName());
        }
        return *this;
    }
};



#endif //SETUTILITY_H
