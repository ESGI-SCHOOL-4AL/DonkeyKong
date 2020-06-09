#include "Controllable.hpp"

#include <iostream>

void Controllable::KeyPressed(sf::Event event)
{
    switch (event.key.code)
    {
    case sf::Keyboard::Up:
        moving_up_ = true;
        break;
    case sf::Keyboard::Down:
        moving_down_ = true;
        break;
    case sf::Keyboard::Left:
        moving_left_ = true;
        break;
    case sf::Keyboard::Right:
        moving_right_ = true;
        break;
    }
}

void Controllable::KeyReleased(sf::Event event)
{
    switch (event.key.code)
    {
    case sf::Keyboard::Up:
        moving_up_ = false;
        break;
    case sf::Keyboard::Down:
        moving_down_ = false;
        break;
    case sf::Keyboard::Left:
        moving_left_ = false;
        break;
    case sf::Keyboard::Right:
        moving_right_ = false;
        break;
    }
}

void Controllable::Draw(std::shared_ptr<sf::RenderWindow> window)
{
    auto pos = sprite_->getPosition();
    if (moving_up_)
    {
        pos.y -= movement_speed_;
    }
    if (moving_down_)
    {
        pos.y += movement_speed_;
    }
    if (moving_left_)
    {
        pos.x -= movement_speed_;
    }
    if (moving_right_)
    {
        pos.x += movement_speed_;
    }
    sprite_->setPosition(pos);
    Entity::Draw(window);
}