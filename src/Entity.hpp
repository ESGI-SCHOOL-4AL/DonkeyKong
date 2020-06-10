#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>

#include "FileNotFoundException.hpp"

#define DEFAULT_X_POSITION 0.f
#define DEFAULT_Y_POSITION 0.f

class Entity : public std::enable_shared_from_this<Entity>
{
public:
    Entity();
    Entity(std::string texture_path);
    Entity(std::string texture_path, float x_position, float y_position);
    virtual ~Entity();

    virtual void Draw(std::shared_ptr<sf::RenderWindow> window);
    virtual void CheckCollisions(std::vector<std::shared_ptr<Entity>> entities);
    virtual void OnCollision(std::shared_ptr<Entity> other_entity);
    std::shared_ptr<sf::Sprite> GetSprite();
    std::string GetTexturePath();
    bool IsDrawable();
    bool IsGravityImpacted();
    sf::Vector2u GetSize();
    void SetPosition(float x_position, float y_position);

    std::shared_ptr<Entity> shared_ptr()
    {
        return shared_from_this();
    }

protected:
    std::shared_ptr<sf::Texture> texture_;
    std::shared_ptr<sf::Sprite> sprite_;
    bool drawable_;
    bool gravity_impacted_;
    std::string texture_path_;
    sf::Vector2u size_;
};

#endif