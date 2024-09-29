//
// Created by imry on 9/24/24.
//

#ifndef SPECIALSQUARE_H
#define SPECIALSQUARE_H
#include "Square.h"
#include <string>

#include "Player.h"


class SpecialSquare : public Square {
public:
    SpecialSquare(const std::string& name);
    void landOn(Player& player) override;
};




#endif //SPECIALSQUARE_H
