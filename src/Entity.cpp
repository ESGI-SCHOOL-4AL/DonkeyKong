#include "Entity.hpp"

Entity::Entity() {}

Entity::Entity(std::string texture_path)
{
    texture_path_ = texture_path;
    texture_ = std::make_shared<sf::Texture>();
    if (!texture_->loadFromFile(texture_path_))
    {
        throw FileNotFoundException();
    }

    sprite_ = std::make_shared<sf::Sprite>();
    sprite_->setTexture(*texture_);
    sprite_->setPosition(DEFAULT_X_POSITION, DEFAULT_Y_POSITION);

    size_ = sf::Vector2u(texture_->getSize());
    drawable_ = false;
    gravity_impacted_ = false;
}

Entity::Entity(std::string texture_path, float x_position, float y_position) : Entity(texture_path)
{
    sprite_->setPosition(x_position, y_position);
}

void Entity::Draw(std::shared_ptr<sf::RenderWindow> window)
{
    if (drawable_)
        window->draw(*sprite_);
}

std::shared_ptr<sf::Sprite> Entity::GetSprite()
{
    return sprite_;
}

std::string Entity::GetTexturePath()
{
    return texture_path_;
}

bool Entity::IsDrawable()
{
    return drawable_;
}

bool Entity::IsGravityImpacted()
{
    return gravity_impacted_;
}

sf::Vector2u Entity::GetSize()
{
    return size_;
}

void Entity::SetPosition(float x_position, float y_position)
{
    sprite_->setPosition(x_position, y_position);
}

Entity::~Entity() {}
