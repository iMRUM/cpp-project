//
// Created by imry on 9/24/24.
//

#ifndef STREET_H
#define STREET_H
#include <string>

#include "Tradeable.hpp"
#include "Player.h"
#include "Property.h"

// Street IS A Square and HAS Properties
class Street : public Square, public Tradeable{
public:
    Street(const std::string &name, int price,int house_cost, int rent, const Player &owner, const Color &type)
       : Square(name), Tradeable(price, rent, owner, type), houseCost(house_cost), numHouses(0), hotel(false) {}


    void buildHouse();
    void buildHotel();

    int getHouseCost() const;
    int getNumHouses() const;
    bool hasHotel() const;

    virtual void landOn(Player& player) override;
private:
    int houseCost;
    int numHouses;
    bool hotel;
};




#endif //STREET_H
