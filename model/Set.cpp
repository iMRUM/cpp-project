//
// Created by imry on 9/24/24.
//

#include "Set.h"


Set::Set(int color, const std::string &name): _color(color), _color_name(name){
}


const std::string& Set::getColorName() const {
    return _color_name;
}
