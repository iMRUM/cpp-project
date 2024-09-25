//
// Created by imry on 9/24/24.
//

#ifndef STREET_H
#define STREET_H
#include <string>

#include "Player.h"
#include "Tradeable.hpp"
#include "Property.h"

// Street IS A Square and HAS Properties
class Street : public Square, public Tradeable{
private:
    int houseCost;
    int houses;
    bool hotel;
public:
    Street(const std::string &name, int price, int rent, int house_cost, const Set &type)
       : Square(name), Tradeable(price, rent, type), houseCost(house_cost), houses(0), hotel(false) {}


    void buildHouse();
    void buildHotel();

    inline int Street::getHouseCost() const {
        return this->houseCost;
    }

    inline int Street::getNumHouses() const {
        return this->houses;
    }

    inline bool Street::hasHotel() const {
        return this->hotel;
    }

    int house_cost() const {
        return houseCost;
    }

    void set_house_cost(int house_cost) {
        houseCost = house_cost;
    }

    int house() const {
        return houses;
    }

    void set_houses(int houses) {
        this->houses = houses;
    }

    virtual void landOn(Player& player) override;

};




#endif //STREET_H
