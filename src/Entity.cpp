#include "Entity.hpp"

Entity::Entity()
{
    sprite_;
    size_;
    position_;
    velocity_;
    drawable_ = true;
    gravity_ = false;
}

bool Entity::CollidesWith(sf::Sprite entity)
{
    return WillCollide(entity, sprite_.getPosition());
}

bool Entity::WillCollide(sf::Sprite entity, sf::Vector2f new_pos)
{
    auto size_entity_texture = entity.getTexture()->getSize();
    auto pos = entity.getPosition();

    bool collidesX = new_pos.x + size_.x >= pos.x && new_pos.x <= pos.x + size_entity_texture.x;
    bool collidesY = new_pos.y + size_.y >= pos.y && new_pos.y <= pos.y + size_entity_texture.y;

    return collidesX && collidesY;
}

void Entity::Update(std::vector<Entity> entities, sf::Time elapsedTime)
{
    sf::Vector2f new_pos = sf::Vector2f(velocity_.x, velocity_.y);

    if (gravity_)
    {
        new_pos += sf::Vector2f(0.f, GRAVITY) * elapsedTime.asSeconds() + sprite_.getPosition();

        for (Entity entity : entities)
        {
            if (WillCollide(entity.sprite_, new_pos))
            {
                return;
            }
        }

        sprite_.move(sf::Vector2f(0.f, GRAVITY) * elapsedTime.asSeconds());
    }
}

void Entity::Draw(sf::RenderWindow *window)
{
    if (drawable_)
        window->draw(sprite_);
}