//
// Created by imry on 9/24/24.
//

#ifndef SQUARE_H
#define SQUARE_H
#include <string>

#include "Player.h"

// Square is inherited by Street(Tradeable), Railroad(Tradeable), Jail, SpecialSquare
class Square {
private:
    std::string _name;
public:
    explicit Square(const std::string &name)
        : _name(name) {
    }

    std::string name() const {
        return _name;
    }

    void set_name(const std::string &name) {
        _name = name;
    }

    virtual ~Square() = default;
    virtual void landOn(Player& player) = 0;

};




#endif //SQUARE_H
