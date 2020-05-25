#include "Mario.hpp"

#include <iostream>

const std::string Mario::MARIO_TEXTURE_PATH = "Media/Textures/Mario_small_transparent.png";

Mario::Mario() : Controllable(MARIO_TEXTURE_PATH)
{
    drawable_ = true;
}

Mario::Mario(float x_position, float y_position) : Controllable(MARIO_TEXTURE_PATH, x_position, y_position)
{
    drawable_ = true;
}

void Mario::KeyPressed(sf::Event event)
{
    switch (event.key.code)
    {
    case sf::Keyboard::Up:
        std::cout << "up pressed" << std::endl;
        break;
    case sf::Keyboard::Down:
        std::cout << "down pressed" << std::endl;
        break;
    case sf::Keyboard::Left:
        std::cout << "left pressed" << std::endl;
        break;
    case sf::Keyboard::Right:
        std::cout << "right pressed" << std::endl;
        break;
    default:
        break;
    }
}

void Mario::KeyReleased(sf::Event event)
{
    switch (event.key.code)
    {
    case sf::Keyboard::Up:
        std::cout << "up released" << std::endl;
        break;
    case sf::Keyboard::Down:
        std::cout << "down released" << std::endl;
        break;
    case sf::Keyboard::Left:
        std::cout << "left released" << std::endl;
        break;
    case sf::Keyboard::Right:
        std::cout << "right released" << std::endl;
        break;
    default:
        break;
    }
}

Mario::~Mario() {}