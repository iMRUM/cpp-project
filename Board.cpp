//
// Created by imry on 9/24/24.
//

#include "Board.h"

std::unique_ptr<Square> Board::getSquare(size_t index) const
{
    return this->squares.at(index);
}

