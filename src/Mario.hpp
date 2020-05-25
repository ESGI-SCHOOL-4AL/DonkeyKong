#ifndef MARIO_HPP
#define MARIO_HPP

#include <string>
#include <iostream>

#include "Entity.hpp"
#include "Controllable.hpp"

class Mario : public Controllable
{
public:
    Mario();
    Mario(float x_position, float y_position);
    void KeyPressed(sf::Event event);
    void KeyReleased(sf::Event event);
    ~Mario();

private:
    static const std::string MARIO_TEXTURE_PATH;
};

#endif