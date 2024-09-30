//
// Created by imry on 9/29/24.
//

#ifndef SETUTILITY_H
#define SETUTILITY_H
#include "Set.h"


class SetUtility: public Set {
public:
    SetUtility(const int color, const string &name)
        : Set(color, name) {
    }
};



#endif //SETUTILITY_H
