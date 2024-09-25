//SGSGSGSGSG
// Created by rodki on 25/09/2024.
//

#ifndef TRADEABLE_HPP
#define TRADEABLE_HPP
#include "Player.h"
#include "Color.h"

class Tradeable {
    int _price;
    int _rent;
    Player _owner;
    Color _type;
public:
    explicit Tradeable(const std::string& name);
    virtual ~Tradeable() = default;
    virtual void landOn(Player& player) = 0;

    Tradeable(const int price, const int rent, const Player &owner, const Color &type)
        : _price(price),
          _rent(rent),
          _owner(owner),
          _type(type) {
    }

    Tradeable(const Tradeable &other)
        : _price(other._price),
          _rent(other._rent),
          _owner(other._owner),
          _type(other._type) {
    }

    Tradeable(Tradeable &&other) noexcept
        : _price(other._price),
          _rent(other._rent),
          _owner(std::move(other._owner)),
          _type(std::move(other._type)) {
    }

    Tradeable & operator=(const Tradeable &other) {
        if (this == &other)
            return *this;
        _price = other._price;
        _rent = other._rent;
        _owner = other._owner;
        _type = other._type;
        return *this;
    }

    Tradeable & operator=(Tradeable &&other) noexcept {
        if (this == &other)
            return *this;
        _price = other._price;
        _rent = other._rent;
        _owner = std::move(other._owner);
        _type = std::move(other._type);
        return *this;
    }

    friend bool operator<(const Tradeable &lhs, const Tradeable &rhs) {
        if (lhs._price < rhs._price)
            return true;
        if (rhs._price < lhs._price)
            return false;
        if (lhs._rent < rhs._rent)
            return true;
        if (rhs._rent < lhs._rent)
            return false;
        if (lhs._owner < rhs._owner)
            return true;
        if (rhs._owner < lhs._owner)
            return false;
        return lhs._type < rhs._type;
    }

    friend bool operator<=(const Tradeable &lhs, const Tradeable &rhs) {
        return !(rhs < lhs);
    }

    friend bool operator>(const Tradeable &lhs, const Tradeable &rhs) {
        return rhs < lhs;
    }

    friend bool operator>=(const Tradeable &lhs, const Tradeable &rhs) {
        return !(lhs < rhs);
    }

    friend bool operator==(const Tradeable &lhs, const Tradeable &rhs) {
        return lhs._price == rhs._price
               && lhs._rent == rhs._rent
               && lhs._owner == rhs._owner
               && lhs._type == rhs._type;
    }

    friend bool operator!=(const Tradeable &lhs, const Tradeable &rhs) {
        return !(lhs == rhs);
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

    Player owner() const {
        return _owner;
    }

    void set_owner(const Player &owner) {
        _owner = owner;
    }

    Color type() const {
        return _type;
    }

    void set_type(const Color &type) {
        _type = type;
    }


};

#endif //TRADEABLE_HPP
