#ifndef CONTROLLABLE_HPP
#define CONTROLLABLE_HPP

#include <SFML/Graphics.hpp>
#include "Entity.hpp"

// Controllable is an abstract class used for entities who respond
// to user controls. The engine will automatically check if the entity
// is controllable and passes it all events of type "sf::Event::KeyPressed" and "sf::Event::KeyReleased".
class Controllable : public Entity
{
public:
    Controllable() : Entity(){};
    Controllable(std::string texture_path) : Entity(texture_path){};
    Controllable(std::string texture_path, float x_position, float y_position) : Entity(texture_path, x_position, y_position){};

    virtual void KeyPressed(sf::Event event) = 0;
    virtual void KeyReleased(sf::Event event) = 0;
};

#endif
