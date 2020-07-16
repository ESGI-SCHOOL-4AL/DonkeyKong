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
    auto other_size = other_entity->GetSize();
    auto other_pos = sprite->getPosition();
    auto pos = sprite_->getPosition();
    if (other_pos.y + other_size.y >= pos.y && other_pos.y + other_size.y <= pos.y + size_.y)
    {
        other_pos.y = pos.y - other_size.y;
        other_entity->SetPosition(other_pos.x, other_pos.y);
    }
}

void Block::CheckCollisions(std::vector<std::shared_ptr<Entity>> entities) {}

Block::~Block() {}