//
// Created by imry on 9/24/24.
//

#ifndef GAME_H
#define GAME_H
#include "Board.h"
#include "Dice.h"
#include "Player.h"
#include "SetStreet.h"
#include "SpecialSquare.h"
//singleton
using namespace std;

class GameLogic{
public:
    GameLogic(int numPlayers, const vector<Player*> &players): bank_balance(32000), players(players), board(){}

    void start();
private:
    int bank_balance;
    vector<Player*> players;
    Board* board;
    vector<pair<unique_ptr<Square>, vector<Player*>>> squares;
    Player* current_player;
    Dice* dice;
    std::vector<int> double_rolls;
    void nextTurn();
    void handlePlayerMove();
    void goneBankrupt(Player& player);
    bool isGameOver();

    //Methods according-ish to their order in actual game
    bool u_decision();
    bool u_valid_payment(int amount);
    bool u_can_build_house(SetStreet* set_street, Street& street);

    void rollDice(); // will call move
    void move(int steps); // wil call land on
    void landOnSquare(int position); // player and square index on board
    void u_landOnTradeable(Tradeable *tradeable); // player can buy, pay rent, or skip
    void _buyTradeable(Tradeable& tradeable);
    void _buildOnStreet(Street &street);
    void _payRent(Player &owner, int rent);
    void _skip();
    void u_landOnSpecialSquare(SpecialSquare *square);
    void _go2Jail(Player& player);
    void _payTax(Player& player);
    void bankrupt();
};



#endif //GAME_H
