//
// Created by imry on 9/24/24.
//

#pragma once
#include <vector>
#include <memory>

#include "model/Constants.h"
#include "Square_class/Square.h"
#include "Square_class/Tradeable_class/Street.h"  // Including specific square types
#include "Square_class/Tradeable_class/Railroad.h"
#include "Square_class/Tradeable_class/Utility.h""

using namespace std;

class Board {
    vector<pair<shared_ptr<Square>, vector<shared_ptr<Player> > > > _squares;

public:
    Board(vector<pair<shared_ptr<Square>, vector<shared_ptr<Player> > > > squares){
        pair<shared_ptr<Square>, vector<shared_ptr<Player> > >& p = squares[0];
        for (const auto& p : squares) {
            _squares.push_back(p);
        }
    }
    // Get a square based on its position on the board__
    shared_ptr<Square> squareAt(int position) const {
        return _squares[position].first;
    }

    shared_ptr<Player> firstPlayerAt(int position) const {
        return _squares[position].second[0];
    }

    std::vector<std::shared_ptr<Player>> getPlayersAt(int position) const{
        return _squares[position].second;
    }

    // Get the total number of squares on the board__
    int getTotalSquares() const {
        return _squares.size();
    }
};

