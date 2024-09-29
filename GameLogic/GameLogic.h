//
// Created by imry on 9/24/24.
//

#ifndef GAME_H
#define GAME_H
#include "Board.h"
#include "Dice.h"
#include "Player.h"
//singleton

//Dice is rolled at the beginning of each "turn"

class GameLogic{
public:
    GameLogic(int numPlayers, std::vector<Player*> players): bank_balance(32000), players(players), board(){}
    void start();
private:
    int bank_balance;
    std::vector<Player*> players;
    Board* board;
    Player* current_player;
    Dice* dice;
    std::vector<int> double_rolls;
    void nextTurn();
    void handlePlayerMove(Player& player);
    void goneBankrupt(Player& player);
    bool isGameOver() {
        return numPlayers<=1;
    }
};



#endif //GAME_H
