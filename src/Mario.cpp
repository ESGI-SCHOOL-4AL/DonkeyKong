#include "Mario.hpp"

#include <iostream>

const std::string Mario::MARIO_TEXTURE_PATH = "Media/Textures/Mario_small_transparent.png";

Mario::Mario() : Entity(MARIO_TEXTURE_PATH)
{
    drawable_ = true;
}

Mario::Mario(float x_position, float y_position) : Entity(MARIO_TEXTURE_PATH, x_position, y_position)
{
    drawable_ = true;
}

void Mario::Move(sf::Event event)
{
    switch (event.key.code)
    {
    case sf::Keyboard::Up:
        std::cout << "up" << std::endl;
        break;
    case sf::Keyboard::Down:
        std::cout << "down" << std::endl;
        break;
    case sf::Keyboard::Left:
        std::cout << "left" << std::endl;
        break;
    case sf::Keyboard::Right:
        std::cout << "right" << std::endl;
        break;
    default:
        break;
    }
}

Mario::~Mario() {}