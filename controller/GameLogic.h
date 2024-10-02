//
// Created by imry on 9/24/24.
//

#ifndef GAME_H
#define GAME_H
#include "../model/Components/Board.h"
#include "../model/Components/Dice.h"
#include "../model/Components/Player.h"
#include "../model/Components/Set_class/SetStreet.h"
#include "../model/Components/Square_class/SpecialSquare.h"
//singleton
using namespace std;

class GameLogic{
public:
    GameLogic(int numPlayers, const vector<Player&> &players): bank_balance(32000), board__(), current_player(players.front()) {
        for (Player p: players) {
            _players.push_back(p);
        }
    }

    void start();
private:
    int bank_balance;
    vector<Player> _players;
    Board* board__;
    vector<pair<unique_ptr<Square>, vector<Player>>> squares;
    Player current_player;
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
    void landOnSquare(int position); // player and square index on board__
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
