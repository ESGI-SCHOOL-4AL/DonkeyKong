#include "Block.hpp"

const std::string Block::BLOCK_TEXTURE_PATH = "Media/Textures/Block.png";

Block::Block() : Entity(BLOCK_TEXTURE_PATH)
{
    drawable_ = true;
}

Block::Block(float x_position, float y_position) : Entity(BLOCK_TEXTURE_PATH, x_position, y_position)
{
    drawable_ = true;
}

void Block::OnCollision(std::shared_ptr<Entity> other_entity)
{
    auto sprite = other_entity->GetSprite();
    auto pos = sprite->getPosition();
    pos.y = sprite_->getPosition().y - other_entity->GetSize().y;
    other_entity->SetPosition(pos.x, pos.y);
}

void Block::CheckCollisions(std::vector<std::shared_ptr<Entity>> entities) {}

Block::~Block() {}