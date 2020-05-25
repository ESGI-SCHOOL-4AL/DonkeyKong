#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <memory>
#include <string>
#include <SFML/Graphics.hpp>

#include "FileNotFoundException.hpp"

#define DEFAULT_X_POSITION 0.f
#define DEFAULT_Y_POSITION 0.f

class Entity
{
public:
    Entity();
    Entity(std::string texture_path);
    Entity(std::string texture_path, float x_position, float y_position);
    virtual ~Entity();

    void Draw(std::shared_ptr<sf::RenderWindow> window);
    std::shared_ptr<sf::Sprite> GetSprite();
    std::string GetTexturePath();
    bool IsDrawable();
    bool IsGravityImpacted();
    sf::Vector2u GetSize();
    void SetPosition(float x_position, float y_position);

protected:
    std::shared_ptr<sf::Texture> texture_;
    std::shared_ptr<sf::Sprite> sprite_;
    bool drawable_;
    bool gravity_impacted_;
    std::string texture_path_;
    sf::Vector2u size_;
};

#endif