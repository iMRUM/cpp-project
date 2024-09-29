//
// Created by imry on 9/24/24.
//

#ifndef PLAYER_H
#define PLAYER_H
#include <memory>
#include <string>
#include <vector>
#include <utility>
#include "Street.h"

using namespace std;
class Player {
private:
    string _name;
    int _position;
    int _money;
    
    pair<string, unique_ptr<Tradeable>> _owned_tradeables;
public:
    Player(const string& name, int initialMoney);

    void move(int steps);
    void addMoney(int amount);
    void subtractMoney(int amount);
    void buyStreet(Street& Street);

    void buyProperty(string street_name, int type);


    bool isBankrupt() const;

    Player(const Player &other)
            : _name(other._name),
              _position(other._position),
              _money(other._money),
              _owned_tradeables(other._owned_tradeables) {
    }

    string name() const {
        return _name;
    }

    void set_name(const string &name) {
        _name = name;
    }

    int position() const {
        return _position;
    }

    void set_position(const int position) {
        _position = position;
    }

    int money() const {
        return _money;
    }

    pair<string, unique_ptr<Tradeable>> owned_tradeables() const {
        return _owned_tradeables;
    }

    void owned_tradeables(const pair<string, unique_ptr<Tradeable>> &owned_tradeables) {
        _owned_tradeables = owned_tradeables;
    }



    Player & operator=(const Player &other) {
        if (this == &other)
            return *this;
        _name = other._name;
        _position = other._position;
        _money = other._money;
        _owned_tradeables = other._owned_tradeables;
        return *this;
    }
};


#endif //PLAYER_H
