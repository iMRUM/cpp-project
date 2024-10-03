//
// Created by imry on 9/24/24.
//

#ifndef PLAYER_H
#define PLAYER_H
#include <map>
#include <memory>
#include <string>
#include <vector>
#include <utility>
#include "Square_class/Tradeable_class/Street.h"


class Tradeable;
using namespace std;
class Player {
private:
    bool _bankrupt;
    bool _jail;
    int _position; // getPosition(index) on board
    int _balance;
    short _doubles_count;
    string _name;
    vector<Tradeable*> _owned_tradeables;
    void modifyMoney(int amount);
public:
    Player(const string& name, const int initialMoney = 1500): _bankrupt(false), _jail(false), _position(0),
                                                               _balance(initialMoney),
                                                               _doubles_count(0), _name(name) {
    }

    Player(const Player &other)
        : _bankrupt(other.isBankrupt()), _jail(other.isInJail()), _position(other.getPosition()),
          _balance(other.getBalance()), _doubles_count(0),
          _name(other.getName()),
          _owned_tradeables(other.getOwnedTradeables()) {
    }

    void move(int steps); //TODO


    void buyStreet(Street& Street);
    void buyProperty(string street_name);

    void receive(int amount);
    int pay(int amount);


    void setInJail(const bool jail) {
        _jail = jail;
    }

    bool isInJail() const {
        return _jail;
    }

    void setBankrupt(const bool bankrupt) {
        this->_bankrupt = bankrupt;
    }

    bool isBankrupt() const {
        return _bankrupt;
    }

    string getName() const {
        return _name;
    }

    void setName(const string &name) {
        _name = name;
    }

    int getPosition() const {
        return _position;
    }

    void setPosition(const int position) {
        _position = position;
    }

    int getBalance() const {
        return _balance;
    }

    vector<Tradeable*> getOwnedTradeables() const {
        return _owned_tradeables;
    }

    void setOwnedTradeables(const vector<Tradeable*> &owned_tradeables) {
        _owned_tradeables = owned_tradeables;
    }

    void incrementDoublesCount() {
        ++_doubles_count;
    }

    void resetDoublesCount() {
        _doubles_count = 0;
    }


    Player & operator=(const Player &other) {
        if (this == &other)
            return *this;
        _name = other.getName();
        _position = other.getPosition();
        _balance = other.getBalance();
        _owned_tradeables = other.getOwnedTradeables();
        return *this;
    }
};


#endif //PLAYER_H
