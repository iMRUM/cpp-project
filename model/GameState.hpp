//
// Created by imry on 10/4/24.
//

#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP
#include <vector>

#include "Components/Board.h"
#include "Components/Player.h"
#include "Components/Square_class/SpecialSquare.h"

//Singleton

class GameState {
private:
    int _bank_balance = 0;
    Board* _board = nullptr;
    Player* _current_player = nullptr;
    vector<Player*> _players;
public:
    GameState(Board* board): _board(board) {}
    ~GameState(){}

    int getBankBalance() const {
        return _bank_balance;
    }

    void setBankBalance(int bank_balance) {
        _bank_balance = bank_balance;
    }

    Player * getCurrentPlayer() const {
        return _current_player;
    }

    void setCurrentPlayer(Player *current_player) {
        _current_player = current_player;
    }

    vector<Player *> getPlayers() const {
        return _players;
    }
    void addPlayer(Player *player) {
        _players.push_back(player);
    }
    void setPlayers(const vector<Player *> &players) {
        _players = players;
    }
    Square* getSquareAt(int index){
        return _board->squareAt(index).get();
    }
};



#endif //GAMESTATE_HPP
