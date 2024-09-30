//SGSGSGSGSG
// Created by rodki on 25/09/2024.
//

#ifndef TRADEABLE_HPP
#define TRADEABLE_HPP

#include "Square.h"
#include "Player.h"
#include "Set.h"

class Tradeable: public Square{
    int _price;
    int _rent;
    Player* _owner;
    std::string _name;
    Set _set;
public:

    Tradeable(const std::string &name, const int price, const int rent, const Set &type_set)
        :Square(name), _price(price),
          _rent(rent), _owner(nullptr),
          _set(type_set) {
    }

    Tradeable(const Tradeable &other)
        : Square(other.name()), _price(other._price),
          _rent(other._rent),
          _owner(other._owner),
          _set(other._set) {
    }
    Tradeable(const unique_ptr<Tradeable> &other)
        : Square(other->name()), _price(other->_price),
          _rent(other->_rent),
          _owner(other->_owner),
          _set(other->_set) {
    }
    ~Tradeable() override = default;

    Tradeable & operator=(const Tradeable &other) {
        if (this == &other)
            return *this;
        _price = other._price;
        _rent = other._rent;
        _owner = other._owner;
        _set = other._set;
        return *this;
    }


    int price() const {
        return _price;
    }

    void set_price(const int price) {
        _price = price;
    }

    int rent() const {
        return _rent;
    }

    void set_rent(const int rent) {
        _rent = rent;
    }

    Player* owner() const {
        return _owner;
    }

    bool hasOwner() const {
        return _owner != nullptr;
    }

    void set_owner(Player* owner) {
        _owner = owner;
    }

    Set type() const {
        return _set;
    }

    void set_type(const Set &type) {
        _set = type;
    }

//Methods

    int landOn(Player *player) override;
    void buy(Player *player);
    bool isTradeable() override {
        return true;
    }
};

#endif //TRADEABLE_HPP
