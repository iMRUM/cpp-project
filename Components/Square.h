#ifndef SQUARE_H
#define SQUARE_H

#include <string>
#include "Player.h"

class Square {
private:
    std::string _name;

protected:
    // Constructor is protected to allow instantiation only by derived classes
    explicit Square(const std::string &name)
        : _name(name) {
    }

public:
    // Copy Constructor
    Square(const Square &other)
        : _name(other.name()) {
    }

    // Copy Assignment Operator
    Square& operator=(const Square &other) {
        if (this != &other) {
            _name = other._name;
        }
        return *this;
    }

    // Virtual Destructor
    virtual ~Square() = default;

    // Getter for name
    std::string name() const {
        return _name;
    }

    // Setter for name
    void set_name(const std::string &name) {
        _name = name;
    }

    // Pure virtual function
    virtual void landOn(Player& player) = 0;
};

#endif // SQUARE_H
