//
// Created by imry on 9/24/24.
//

#ifndef PROPERTY_H
#define PROPERTY_H
#include "Square.h"
#include "Player.h"
//Hotel costs as 4 houses + 100NIS






/*TOO WRONG, PROPERTY IS "HOUSE" or "HOTEL"*/
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
    int _price;
    int _rent;
    Player* _owner;
};





#endif //PROPERTY_H
