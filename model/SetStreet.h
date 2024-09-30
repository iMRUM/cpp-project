//
// Created by imry on 9/29/24.
//

#ifndef SETSTREET_H
#define SETSTREET_H
#include "Set.h"


class SetStreet : public Set{
private:
    vector<Street*> _streets;
public:
    SetStreet(int color, const string& name, const vector<Street*>& streets): Set(color, name), _streets(streets){}
    // Destructor (Rule of Three): Clears the vector and deletes the Street pointers
    ~SetStreet() {
        for (Street* street : _streets) {
            delete street;
        }
    }

    // Copy Constructor (Rule of Three): Performs deep copy
    SetStreet(const SetStreet& other) : Set(other) {
        for (Street* street : other._streets) {
            // Assuming Street has a copy constructor
            _streets.push_back(new Street(*street));
        }
    }

    // Copy Assignment Operator (Rule of Three): Performs deep copy with self-assignment check
    SetStreet& operator=(const SetStreet& other) {
        if (this != &other) {
            // Clear existing streets
            for (Street* street : _streets) {
                delete street;
            }
            _streets.clear();

            // Copy the base class
            Set::operator=(other);

            // Copy streets from the other object
            for (Street* street : other._streets) {
                _streets.push_back(new Street(*street));
            }
        }
        return *this;
    }
    // Helper function to ensure balanced house-building
    bool canBuildHouseOnStreet(Street* street, Player* owner) const;
    int isCompleteSetOwned(Player *owner) const;
};



#endif //SETSTREET_H
