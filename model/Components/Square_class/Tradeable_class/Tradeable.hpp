//SGSGSGSGSG
// Created by rodki on 25/09/2024.
//

#ifndef TRADEABLE_HPP
#define TRADEABLE_HPP

#include "../Square.h"
#include "Player.h"
#include "../../Set_class/Set.h"

class Player;
class Square;
class Player;
class Set;

class Tradeable: public Square{
    int _price;
    int _rent;
    std::string _name;
    Player* _owner;
public:

    Tradeable(const std::string &name, const int price, const int rent, shared_ptr<Set> type_set)
        :Square(name, type_set), _price(price),
          _rent(rent), _owner(nullptr){}

    Tradeable(const Tradeable &other)
        : Square(other.getName(), other.getSet()), _price(other._price),
          _rent(other._rent),
          _owner(other._owner){}
    Tradeable(const shared_ptr<Tradeable> &other)
        : Square(other->getName(), other->getSet()), _price(other->_price),
          _rent(other->_rent),
          _owner(other->_owner){}

    virtual ~Tradeable() override {
        delete _owner;

    }

    Tradeable & operator=(const Tradeable &other) {
        if (this == &other)
            return *this;
        setPrice(other.getPrice());
        setRent(other.getRent());
        setOwner(other.getOwner());
        setSet(other.getSet());
        return *this;
    }


    int getPrice() const {
        return _price;
    }

    void setPrice(const int price) {
        _price = price;
    }

    int getRent() const {
        return _rent;
    }

    void setRent(const int rent) {
        _rent = rent;
    }

    Player* getOwner() const {
        return _owner;
    }

    bool hasOwner() const {
        return _owner != nullptr;
    }

    void setOwner(Player* owner) {
        _owner = owner;
    }


//Methods

    int landOn(Player *player) override;
    void buy(Player *player);
    bool isTradeable() override {
        return true;
    }
};

#endif //TRADEABLE_HPP
