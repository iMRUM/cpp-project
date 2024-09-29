//
// Created by imry on 9/24/24.
//

#ifndef BOARD_H
#define BOARD_H
#include <memory>
#include <Square.h>
#include <vector>

class Board {
public:
    explicit Board(const std::vector<std::unique_ptr<Square>> &squares)
        : squares(squares) {
    }
    std::unique_ptr<Square> getSquare(size_t index) const;
private:
    std::vector<std::unique_ptr<Square>> squares;
    void initializeSquares();
};

#endif //BOARD_H
