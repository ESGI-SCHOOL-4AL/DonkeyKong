#include "Block.hpp"

Block::Block() {
    sf::Texture block_texture = sf::Texture();
    block_texture.loadFromFile(Block::blockTexturePath);
    
    drawable_ = true;
    sprite_.setTexture(block_texture);
    size_ = sf::Vector2u(BLOCK_WIDHT, BLOCK_HEIGHT);
}