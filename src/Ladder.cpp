#include "Ladder.hpp"
#include "Controllable.hpp"

const std::string Ladder::LADDER_TEXTURE_PATH = "Media/Textures/Echelle.png";

Ladder::Ladder() : Entity(LADDER_TEXTURE_PATH)
{
    drawable_ = true;
}

Ladder::Ladder(float x_position, float y_position) : Entity(LADDER_TEXTURE_PATH, x_position, y_position)
{
    drawable_ = true;
}

void Ladder::OnCollision(std::shared_ptr<Entity> other_entity)
{
    auto controllable = std::dynamic_pointer_cast<Controllable>(other_entity);
    if (controllable)
    {
        auto sprite = other_entity->GetSprite();
        auto pos = sprite->getPosition();
        pos.y -= controllable->gravity_;
        other_entity->SetPosition(pos.x, pos.y);
    }
}

Ladder::~Ladder() {}