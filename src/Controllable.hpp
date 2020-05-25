#ifndef CONTROLLABLE_HPP
#define CONTROLLABLE_HPP

#include <SFML/Graphics.hpp>

// Controllable is an abstract class used for entities who respond
// to user controls. The engine will automatically check if the entity
// is controllable and passes it all events of type "sf::Event::KeyPressed".
class Controllable
{
public:
    virtual void Move(sf::Event event) = 0;
};

#endif
