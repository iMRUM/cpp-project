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
    Board();
    Square* getSquare(int index);
private:
    std::vector<std::unique_ptr<Square>> squares;
    void initializeSquares();
};

#endif //BOARD_H
