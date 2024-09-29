//
// Created by imry on 9/24/24.
//

#ifndef GAME_H
#define GAME_H
#include "Board.h"
#include "Player.h"
//singleton


class GameLogic{
public:
    GameLogic(int numPlayers);
    void start();
private:
    std::vector<Player> players;
    Board board;
    int currentPlayerIndex;

    void nextTurn();
    void handlePlayerMove(Player& player);
};



#endif //GAME_H
