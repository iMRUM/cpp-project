//
// Created by imry on 9/24/24.
//

#ifndef GAME_H
#define GAME_H
#include "Board.h"
#include "Dice.h"
#include "Player.h"
#include "Components/SpecialSquare.h"
//singleton

//Dice is rolled at the beginning of each "turn"

class GameLogic{
public:
    GameLogic(int numPlayers, const std::vector<Player*> &players): bank_balance(32000), players(players), board(){}
    void start();
private:
    int bank_balance;
    std::vector<Player*> players;
    Board* board;
    std::vector<std::unique_ptr<Square>> squares;
    Player* current_player;
    Dice* dice;
    std::vector<int> double_rolls;
    void nextTurn();
    void handlePlayerMove(Player& player);
    void goneBankrupt(Player& player);
    bool isGameOver();

    //Methods according-ish to their order in actual game
    bool u_decision();
    bool u_valid_payment(Player& player, int amount);
    void rollDice(); // will call move
    void move(Player& player, int steps); // wil call land on
    void landOnSquare(Player& player, int position); // player and square index on board
    void u_landOnTradeable(Player &player, Tradeable *tradeable); // player can buy, pay rent, or skip
    void _buyTradeable(Player& player, Tradeable& tradeable);
    void _buildOnTradeable(Player& player, Tradeable& tradeable);
    void _payRent(Player &player, Player &owner, int rent);
    void _skip(Player& player);
    void u_landOnSpecialSquare(Player &player, SpecialSquare *square);
    void _go2Jail(Player& player);
    void _payTax(Player& player);
    void bankrupt(Player& player);
};



#endif //GAME_H
