#ifndef BLOCK_HPP
#define BLOCK_HPP

#include <string>

#include <SFML/Graphics.hpp>

#include "Entity.hpp"

class Block : public Entity
{
public:
    Block();
    Block(float x_position, float y_position);
    void OnCollision(std::shared_ptr<Entity> other_entity) override;
    void CheckCollisions(std::vector<std::shared_ptr<Entity>> entities) override;
    ~Block();

private:
    static const std::string BLOCK_TEXTURE_PATH;
};

#endif