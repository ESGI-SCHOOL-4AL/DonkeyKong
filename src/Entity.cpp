#include "Entity.hpp"

Entity::Entity() {
    drawable_ = false;
	gravity_ = false;
}

bool Entity::CollidesWith(sf::Sprite entity) {
    return WillCollide(entity, sprite_.getPosition());
}

bool Entity::WillCollide(sf::Sprite entity, sf::Vector2f new_pos) {
    auto size_entity_texture = entity.getTexture()->getSize();
    auto pos = entity.getPosition();

    bool collidesX = new_pos.x + size_.x >= pos.x && new_pos.x <= pos.x + size_entity_texture.x;
    bool collidesY = new_pos.y + size_.y >= pos.y && new_pos.y <= pos.y + size_entity_texture.y;

    return collidesX && collidesY;
}

void Entity::Update(Game* game, sf::Time elapsedTime) {
    sf::Vector2f new_pos = sf::Vector2f(velocity_.x, velocity_.y);
    
    if (gravity_) {
        new_pos += sf::Vector2f(0.f, GRAVITY) * elapsedTime.asSeconds() + sprite_.getPosition();
        
        for (int i = 0; i < BLOCK_COUNT_X; i++) {
            for (int j = 0; j < BLOCK_COUNT_Y; j++) {
                auto platform = game->block_[i][j];
                if(WillCollide(platform, new_pos)) {
                    return;
                }
            }
        }

	    sprite_.move(sf::Vector2f(0.f, GRAVITY) * elapsedTime.asSeconds());
    }
}