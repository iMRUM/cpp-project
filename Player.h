//
// Created by imry on 9/24/24.
//

#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <vector>

#include "Street.h"


class Player {
private:
    std::string _name;
    int _position;
    int _money;
    std::vector<Street*> _owned_streets;
public:
    Player(const std::string& name, int initialMoney);

    void move(int steps);
    void addMoney(int amount);
    void subtractMoney(int amount);
    void buyStreet(Street& Street);
    

    bool isBankrupt() const;

    std::string name() const {
        return _name;
    }

    void set_name(const std::string &name) {
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

    std::vector<Street *> streets() const {
        return _owned_streets;
    }

    void set_owned_streets1(const std::vector<Street *> &owned_streets) {
        _owned_streets = owned_streets;
    }

    std::vector<Street *> owned_streets() const {
        return _owned_streets;
    }

    void set_owned_streets(const std::vector<Street *> &owned_streets) {
        owned_streets = owned_streets;
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
