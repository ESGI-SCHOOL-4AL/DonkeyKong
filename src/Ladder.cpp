#include "Ladder.hpp"

Ladder::Ladder() {
    sf::Texture ladder_texture = sf::Texture();
    ladder_texture.loadFromFile(Ladder::ladderTexturePath);
    
    drawable_ = true;
    sprite_.setTexture(ladder_texture);
    size_ = sf::Vector2u(LADDER_WIDTH, LADDER_HEIGHT);

}