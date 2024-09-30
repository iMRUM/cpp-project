//
// Created by imry on 9/24/24.
//

#ifndef STREET_H
#define STREET_H
#include <string>

#include "Player.h"
#include "Tradeable.hpp"

// Street IS A Tradeable
class Street : public Tradeable{
private:
    int houseCost;
    int houses;
    bool hotel;
public:
    Street(const std::string &name, int price, int rent, int house_cost, const Set &type)
       :Tradeable(name, price, rent, type), houseCost(house_cost), houses(0), hotel(false) {}


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

    virtual int landOn(Player *player) override;

    // Assignment operator to handle std::unique_ptr<Street>
    Street& operator=(std::unique_ptr<Street> other) {
        if (this != other.get()) {  // Self-assignment check
            // Transfer data from the other Street
            this->houseCost = other->houseCost;
            this->houses = other->houses;
            this->hotel = other->hotel;
            this->set_price(other->price());   // Assuming Tradeable has setPrice()
            this->set_rent(other->rent());     // Assuming Tradeable has setRent()
            this->set_name(other->name());     // Assuming Square has setName()
            this->set_type(other->type());     // Assuming Tradeable has setType()
        }
        return *this;
    }
    unique_ptr<Street> operator()(std::unique_ptr<Tradeable> tradeablePtr) const {
        // Attempt to cast the raw pointer from the unique_ptr
        Street* streetPtr = dynamic_cast<Street*>(tradeablePtr.get());

        if (streetPtr) {
            // Release the ownership from the tradeablePtr and cast it to unique_ptr<Street>
            tradeablePtr.release();
            return std::unique_ptr<Street>(streetPtr);
        }
            // Return nullptr if the cast fails
            return nullptr;
        }
};




#endif //STREET_H
