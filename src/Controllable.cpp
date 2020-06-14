#include "Controllable.hpp"

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
    Entity::Draw(window);
}

void Controllable::CheckCollisions(std::vector<std::shared_ptr<Entity>> entities)
{
    auto pos = sprite_->getPosition();

    // If ladder
    if (moving_up_)
    {
        pos.y -= movement_speed_;
    }
    if (moving_down_)
    {
        pos.y += movement_speed_;
    }

    // If platform or ladder
    if (moving_left_)
    {
        pos.x -= movement_speed_;
    }
    if (moving_right_)
    {
        pos.x += movement_speed_;
    }

    // Gravity
    pos.y += gravity_;

    sprite_->setPosition(pos);
    for (auto &entity : entities)
    {
        if (this->GetSprite() == entity->GetSprite())
        {
            continue;
        }
        auto sprite = entity->GetSprite();
        auto other_pos = sprite->getPosition();
        auto other_size = entity->GetSize();
        auto pos = sprite_->getPosition();

        auto left_boundary = pos.x;
        auto right_boundary = pos.x + size_.x;
        auto top_boundary = pos.y;
        auto bottom_boundary = pos.y + size_.y;

        if (
            ((left_boundary >= other_pos.x && left_boundary <= other_pos.x + other_size.x) ||
             (right_boundary >= other_pos.x && right_boundary <= other_pos.x + other_size.x)) &&
            (/* (top_boundary >= other_pos.y && top_boundary <= other_pos.y + other_size.y) || */
             (bottom_boundary >= other_pos.y && bottom_boundary <= other_pos.y + other_size.y)))
        {
            entity->OnCollision(shared_ptr());
            break;
        }
    }
}

void Controllable::OnCollision(std::shared_ptr<Entity> other_entity) {}