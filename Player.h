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

    pair<string, Street *> owned_streets() const {
        return _owned_streets;
    }


    friend bool operator==(const Player &lhs, const Player &rhs) {
        return lhs.name() == rhs.name()
               && lhs.position() == rhs.position()
               && lhs.money() == rhs.money()
               && lhs.owned_streets() == rhs.owned_streets();
    }
    friend bool operator==(const Player &lhs, const Player *rhs) {
        return lhs.name() == rhs->name()
               && lhs.position() == rhs->position()
               && lhs.money() == rhs->money()
               && lhs.owned_streets() == rhs->owned_streets();
    }

    friend bool operator!=(const Player &lhs, const Player &rhs) {
        return !(lhs == rhs);
    }


};


#endif //PLAYER_H
