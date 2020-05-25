#include "Block.hpp"

const std::string Block::BLOCK_TEXTURE_PATH = "Media/Textures/Block.png";

Block::Block() : Entity(BLOCK_TEXTURE_PATH) {
    drawable_ = true;
 }

Block::Block(float x_position, float y_position) : Entity(BLOCK_TEXTURE_PATH, x_position, y_position) {
    drawable_ = true;
}

Block::~Block() { }