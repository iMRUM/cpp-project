//
// Created by imry on 9/24/24.
//

#include "Square.h"

Square::Square(const std::string &name): _name(name){
}

const std::string & Square::getName() const {
    return this->_name;
}
