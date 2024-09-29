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
#include "Components/Street.h"


using namespace std;
class Player {
private:
    string _name;
    int _position; // position(index) on board
    int _money;
    map<string, unique_ptr<Tradeable>> _owned_tradeables;
    void modifyMoney(int amount);
public:
    Player(const string& name, const int initialMoney = 1500): _name(name), _position(0), _money(initialMoney) {}
    Player(const Player &other)
            : _name(other.name()),
              _position(other.position()),
              _money(other.money()),
              _owned_tradeables(other.owned_tradeables()) {
    }

    void move(int steps);


    void buyStreet(Street& Street);
    void buyProperty(string street_name);

    void receive(int amount);
    int pay(int amount);





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

    map<string, unique_ptr<Tradeable>> owned_tradeables() const {
        return _owned_tradeables;
    }

    void set_owned_tradeables(const map<string, unique_ptr<Tradeable>> &owned_tradeables) {
        _owned_tradeables = owned_tradeables;
    }



    Player & operator=(const Player &other) {
        if (this == &other)
            return *this;
        _name = other.name();
        _position = other.position();
        _money = other.money();
        _owned_tradeables = other.owned_tradeables();
        return *this;
    }
};


#endif //PLAYER_H
