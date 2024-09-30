//
// Created by imry on 9/24/24.
//

#include "GameLogic.h"

#include "Components/SpecialSquare.h"

void GameLogic::start() { //cg
    while (!isGameOver()) {
        for (Player* player : players) {
            current_player = player;
            handlePlayerMove();
        }
    }
}

void GameLogic::nextTurn() { //cg
}

void GameLogic::handlePlayerMove() { //cg
    //if not in jail
    rollDice();
    //else

}

void GameLogic::goneBankrupt(Player &player) { //cg
}

bool GameLogic::isGameOver() { //cg
}

void GameLogic::rollDice() { // maybe apply this idea later for rest of methods (using currrent_player instead of sending)
    move(dice->roll());
}

void GameLogic::move(int steps) {
    int pos = current_player->position();
    vector<Player*> playersOnSquare = squares[pos].second;
    playersOnSquare.erase(playersOnSquare.begin()); // fifo in vector because of "turns"
    squares[pos+steps].second.push_back(current_player);
    landOnSquare(pos+steps);

}

void GameLogic::landOnSquare(int position) {
    // Get the raw pointer to the Square object at the given position
    Square* square = squares[position].first.get();

    if (square->isTradeable()) {
        // Perform dynamic cast and check if it succeeded
        Tradeable* tradeableSquare = dynamic_cast<Tradeable*>(square);
        if (tradeableSquare) {
            u_landOnTradeable(tradeableSquare);
        } else {
            // Handle unexpected type cast failure
            std::cerr << "Error: dynamic_cast to Tradeable failed." << std::endl;
        }
    } else {
        // Perform dynamic cast and check if it succeeded
        SpecialSquare* specialSquare = dynamic_cast<SpecialSquare*>(square);
        if (specialSquare) {
            u_landOnSpecialSquare(specialSquare);
        } else {
            // Handle unexpected type cast failure
            std::cerr << "Error: dynamic_cast to SpecialSquare failed." << std::endl;
        }
    }
}

void GameLogic::u_landOnTradeable(Tradeable *tradeable) {
    switch(tradeable->landOn(current_player)) {
        case -1:
            // would you like to build?
                if (tradeable->type().getColorName() != "Utility") {
                    Street* street = dynamic_cast<Street*> (tradeable);
                    u_decision()?_buildOnStreet(*street):_skip();
                }else {
                    _skip();
                }
                break;
        case 0:
            // would u like to buy?
                u_decision()?_buyTradeable(*tradeable):_skip();
                break;
        default:
            _payRent(tradeable->owner(), tradeable->rent());
    }
}

void GameLogic::_buyTradeable(Tradeable &tradeable) {
    const int amount = tradeable.price();
    if (u_valid_payment(amount)) {
        tradeable.buy(*current_player);
        current_player->pay(amount);
    }
    else {
        //Couldn't buy
        _skip();
    }
}

void GameLogic::_buildOnStreet(Street &street) {
    if (u_valid_payment(street.house_cost()) && u_can_build_house(dynamic_cast<SetStreet*>(street.type()), street)) {
        street.buildHouse(); // will need to change buildHouse to handle hotels automatically
    }
    else {
        //Couldn't buy
        _skip();
    }
}

void GameLogic::_payRent(Player &owner, int rent) {
    if (!u_valid_payment(rent)) {
        bankrupt();
    }
    owner.receive(current_player->pay(rent));
    _skip();
}

void GameLogic::_skip() {
}

void GameLogic::u_landOnSpecialSquare(SpecialSquare* square) {
}

void GameLogic::_go2Jail(Player &player) {
}

void GameLogic::_payTax(Player &player) {
}

void GameLogic::bankrupt() {
    //print current_player is bankrupt
    return;
}



