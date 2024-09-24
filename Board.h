//
// Created by imry on 9/24/24.
//

#ifndef BOARD_H
#define BOARD_H
class Board {
public:
    Board();
    Square* getSquare(int index);
private:
    std::vector<std::unique_ptr<Square>> squares;
    void initializeSquares();
};

#endif //BOARD_H
