//
// Created by imry on 9/24/24.
//

#include "GameLogic.h"

#include "Components/SpecialSquare.h"

void GameLogic::start() { //cg
}

void GameLogic::nextTurn() { //cg
}

void GameLogic::handlePlayerMove(Player &player) { //cg
}

void GameLogic::goneBankrupt(Player &player) { //cg
}

bool GameLogic::isGameOver() { //cg
}

void GameLogic::rollDice() { // maybe apply this idea later for rest of methods (using currrent_player instead of sending)
    move(*current_player, dice->roll());
}

void GameLogic::move(Player &player, int steps) {
}

void GameLogic::landOnSquare(Player &player, int position) { // 0 for tradeable, 1 for special
    Square* square = squares.at(position).get();
    if (square->isTradeable()) {
        u_landOnTradeable(player, dynamic_cast<Tradeable*> (square));
    }
    else {
        u_landOnSpecialSquare(player, dynamic_cast<SpecialSquare*> (square));
    }
}

void GameLogic::u_landOnTradeable(Player &player, Tradeable *tradeable) {
    switch(tradeable->landOn(player)) {
        case -1:
            // would you like to build?
                u_decision()?_buildOnTradeable(player, *tradeable):_skip(player);
                break;
        case 0:
            // would u like to buy?
                u_decision()?_buyTradeable(player, *tradeable):_skip(player);
                break;
        default:
            _payRent(player, tradeable->owner(), tradeable->rent());
    }
}

void GameLogic::_buyTradeable(Player &player, Tradeable &tradeable) {
    int amount = tradeable.price();
    if (u_valid_payment(player, amount)) {
        tradeable.buy(player);
        player.pay(amount);
    }
    else {
        //Couldn't buy
        _skip(player);
    }
}

void GameLogic::_buildOnTradeable(Player &player, Tradeable &tradeable) {
    //if tradeable is street, check house validation
}

void GameLogic::_payRent(Player &player, Player &owner, int rent) {
    if (!u_valid_payment(player, rent)) {
        bankrupt(player);
    }
    owner.receive(player.pay(rent));
    _skip(player);
}

void GameLogic::_skip(Player &player) {
}

void GameLogic::u_landOnSpecialSquare(Player &player, SpecialSquare* square) {
}

void GameLogic::_go2Jail(Player &player) {
}

void GameLogic::_payTax(Player &player) {
}

void GameLogic::bankrupt(Player &player) {
}



