//
// Created by imry on 9/24/24.
//

#ifndef DICE_H
#define DICE_H
#include <utility>


class Dice {
    size_t double_roll[8] = {0};
public:
    Dice();
    int roll();  // Returns the result of two dice rolls
};




#endif //DICE_H
