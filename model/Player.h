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
#include "Street.h"


using namespace std;
class Player {
private:
    bool _bankrupt;
    int _position; // getPosition(index) on board
    int _balance;
    string _name;
    map<string, unique_ptr<Tradeable>> _owned_tradeables;
    void modifyMoney(int amount);
public:
    Player(const string& name, const int initialMoney = 1500): _name(name), _position(0), _balance(initialMoney),
                                                               _bankrupt(false) {
    }

    Player(const Player &other)
            : _name(other.getName()),
              _position(other.getPosition()),
              _balance(other.getBalance()),
              _owned_tradeables(other.getOwnedTradeables()) {
    }

    void move(int steps);


    void buyStreet(Street& Street);
    void buyProperty(string street_name);

    void receive(int amount);
    int pay(int amount);




    void setBankrupt(bool bankrupt) {
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

    map<string, unique_ptr<Tradeable>> getOwnedTradeables() const {
        return _owned_tradeables;
    }

    void setOwnedTradeables(const map<string, unique_ptr<Tradeable>> &owned_tradeables) {
        _owned_tradeables = owned_tradeables;
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
