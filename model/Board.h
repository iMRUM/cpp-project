//
// Created by imry on 9/24/24.
//

#ifndef BOARD_H
#define BOARD_H
#include <memory>
#include "Square.h"
#include <vector>

class Square;

class Board {
public:
    static Board* getInstance()
    std::unique_ptr<Square> getSquare(size_t index) const;
private:
    static Board* instance;
    std::vector<std::unique_ptr<Square>> squares;
    Board(const std::vector<std::unique_ptr<Square>> &squares) : squares(squares) {
    }

    void initializeSquares();
};

#endif //BOARD_H
