#ifndef LADDER_HPP
#define LADDER_HPP

#include <string>

#include "Entity.hpp"

class Ladder : public Entity
{
public:
    Ladder();
    Ladder(float x_position, float y_position);
    void OnCollision(std::shared_ptr<Entity> other_entity) override;
    ~Ladder();

private:
    static const std::string LADDER_TEXTURE_PATH;
};

#endif