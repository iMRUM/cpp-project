//
// Created by imry on 10/2/24.
//

#ifndef SETTRADEABLE_HPP
#define SETTRADEABLE_HPP
#include "Set.h"

using namespace std;

class SetTradeable : public Set{
    vector<shared_ptr<Tradeable>> _tradeables;
    public:
    SetTradeable(int color, const string &name, const vector<shared_ptr<Tradeable>> &tradeables): Set(color, name) {
        for (const auto& tradeable : tradeables) {
            _tradeables.push_back(tradeable);
        }
    }


};



#endif //SETTRADEABLE_HPP
