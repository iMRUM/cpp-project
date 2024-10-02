//
// Created by imry on 9/24/24.
//

#ifndef COLOR_HPP
#define COLOR_HPP

#include <string>
using namespace std;

class Set {
private:
    int _color;
    string _color_name;

public:
    Set(int color, const string &name): _color(color), _color_name(name) {
    }

    virtual ~Set() = default;

    Set(const Set &other)
        : _color(other._color),
          _color_name(other._color_name) {
    }

    Set &operator=(const Set &other) {
        if (this != &other) {
            _color = other._color;
            _color_name = other._color_name;
        }
        return *this;
    }

    int getColor() const {
        return _color;
    }

    void setColor(int color) {
        _color = color;
    }

    string getColorName() const {
        return _color_name;
    }

    void setColorName(const string &color_name) {
        _color_name = color_name;
    }
};

#endif // COLOR_HPP

