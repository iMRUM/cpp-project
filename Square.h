//
// Created by imry on 9/24/24.
//

#ifndef SQUARE_H
#define SQUARE_H
#include <string>

#include "Player.h"

// Square is inherited by Street(Tradeable), Railroad(Tradeable), Jail, SpecialSquare
class Square {
public:
    explicit Square(const std::string& name);
    virtual ~Square() = default;

    virtual void landOn(Player& player) = 0;

    const std::string& getName() const;
private:
    std::string _name;
};




#endif //SQUARE_H
