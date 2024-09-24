//
// Created by imry on 9/24/24.
//

#ifndef PLAYER_H
#define PLAYER_H



class Player {
public:
    Player(const std::string& name, int initialMoney);

    void move(int steps);
    void addMoney(int amount);
    void subtractMoney(int amount);
    void buyProperty(Property& property);

    int getPosition() const;
    int getMoney() const;
    const std::string& getName() const;

    bool isBankrupt() const;

private:
    std::string name;
    int position;
    int money;
    std::vector<Property*> ownedProperties;
};


#endif //PLAYER_H
