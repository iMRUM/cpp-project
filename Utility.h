//
// Created by imry on 9/24/24.
//

#ifndef UTILITY_H
#define UTILITY_H
#include "Player.h"


class Utility : public Property {
public:
    Utility(const std::string& name, int price);
    virtual void landOn(Player& player) override;
};




#endif //UTILITY_H
