#include "Entity.hpp"

Entity::Entity() { }

Entity::Entity(std::string texture_path) {
    texture_path_ = texture_path;
    if(! texture_.loadFromFile(texture_path_)) {
        throw FileNotFoundException();
    }

    sprite_->setTexture(texture_);
    sprite_->setPosition(DEFAULT_X_POSITION, DEFAULT_Y_POSITION);

    drawable_ = false;
    gravity_impacted_ = false;
}

Entity::Entity(std::string texture_path, float x_position, float y_position) {
    texture_path_ = texture_path;
    if(! texture_.loadFromFile(texture_path_)) {
        throw FileNotFoundException();
    }

    sprite_ = std::make_shared<sf::Sprite>();
    sprite_->setTexture(texture_);
    sprite_->setPosition(x_position, y_position);

    drawable_ = false;
    gravity_impacted_ = false;
}

void Entity::Draw(std::shared_ptr<sf::RenderWindow> window) {
    if (drawable_) 
        window->draw(*sprite_);
}

std::shared_ptr<sf::Sprite> Entity::GetSprite() { 
    return sprite_;
}

std::string Entity::GetTexturePath() {
    return texture_path_;
}

bool Entity::IsDrawable() {
    return drawable_;
}

bool Entity::IsGravityImpacted() {
    return gravity_impacted_;
}


Entity::~Entity() { }
