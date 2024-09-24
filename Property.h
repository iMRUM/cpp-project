//
// Created by imry on 9/24/24.
//

#ifndef PROPERTY_H
#define PROPERTY_H
#include "Square.h"

#include "Player.h"


class Property : public Square {
public:
    Property(const std::string& name, int price, int rent);
    virtual ~Property() = default;

    void setOwner(Player* owner);
    Player* getOwner() const;

    virtual void landOn(Player& player) override;

    int getPrice() const;
    int getRent() const;
private:
    int price;
    int rent;
    Player* owner;
};




#endif //PROPERTY_H
