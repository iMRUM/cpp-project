//
// Created by imry on 9/24/24.
//

#ifndef SPECIALSQUARE_H
#define SPECIALSQUARE_H



class SpecialSquare : public Square {
public:
    SpecialSquare(const std::string& name);
    virtual void landOn(Player& player) override;
};




#endif //SPECIALSQUARE_H
