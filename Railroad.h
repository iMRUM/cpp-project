//
// Created by imry on 9/24/24.
//

#ifndef RAILROAD_H
#define RAILROAD_H



class Railroad : public Property {
public:
    Railroad(const std::string& name, int price);
    virtual void landOn(Player& player) override;
};




#endif //RAILROAD_H
