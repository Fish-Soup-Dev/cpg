#ifndef COLOR_HPP
#define COLOR_HPP

#include <string>

enum COLORS
{
    Red = 31,
    Green = 32,
    Yellow = 33,
    Blue = 34,
    Gray = 90,
    Defult = 0,
};

std::string color(enum COLORS color)
{
    return "\033[" + std::to_string(color) + "m";
}

#endif