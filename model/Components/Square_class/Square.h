#ifndef SQUARE_H
#define SQUARE_H

#include <string>
#include "../Player.h"
#include "../Set_class/Set.h"
#include "../../Constants.h"

class Player;
using namespace std;
using namespace Constants;
class Square {
private:
    string _name;
    Set* _set;

protected:
    // Constructor is protected to allow instantiation only by derived classes
    Square(const string &name, Set* set)
        : _name(name), _set(set) {
    }

public:
    // Copy Constructor
    Square(const Square &other)
        : _name(other.getName()), _set(other.getSet()) {
    }

    // Copy Assignment Operator
    Square& operator=(const Square &other) {
        if (this != &other) {
            _name = other.getName();
            _set = other.getSet();
        }
        return *this;
    }

    // Virtual Destructor
    virtual ~Square() = default;

    // Getter for getName
    string getName() const {
        return _name;
    }

    // Setter for getName
    void setName(const string &name) {
        _name = name;
    }

    void setSet(const shared_ptr<Set>& set) {
        _set = set;
    }
    shared_ptr<Set> getSet() const{
        return _set;
    }

    virtual bool isTradeable() {
        return false;
    }
    // Pure virtual function
    virtual int landOn(Player *player) = 0;
};

#endif // SQUARE_H
