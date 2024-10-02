//
// Created by imry on 9/29/24.
//

#ifndef SETSTREET_H
#define SETSTREET_H
#include "Set.h"
#include "../Square_class/Tradeable_class/Street.h"


class SetStreet : public Set{
public:
    SetStreet(int color, const string& name): Set(color, name){}

    // Destructor (Rule of Three)
    ~SetStreet() override = default;

    // Copy Constructor (Rule of Three): Performs deep copy
    SetStreet(const SetStreet& other): Set(other) {}

    // Copy Assignment Operator (Rule of Three): Performs deep copy with self-assignment check
    SetStreet& operator=(const SetStreet& other) {
        if (this != &other) {
            setColor(other.getColor());
            setColorName(other.getColorName());
        }
        return *this;
    }
    // Helper function to ensure balanced house-building
    bool canBuildHouseOnStreet(Street* street, Player* owner) const;
    int isCompleteSetOwned(Player *owner) const;
};



#endif //SETSTREET_H
