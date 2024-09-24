//
// Created by imry on 9/24/24.
//

#ifndef STREET_H
#define STREET_H
#include <string>

#include "Player.h"
#include "Property.h"


class Street : public Property {
public:
    Street(const std::string& name, int price, int rent, int houseCost);
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
