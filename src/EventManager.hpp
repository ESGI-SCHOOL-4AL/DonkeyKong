#ifndef EVENT_MANAGER_HPP
#define EVENT_MANAGER_HPP

#include <memory>
#include <SFML/Graphics.hpp>

#include "Controllable.hpp"

class EventManager
{
public:
    EventManager();
    EventManager(std::shared_ptr<sf::RenderWindow> window);
    ~EventManager();
    void RegisterControllableEntity(std::shared_ptr<Controllable> controllable);
    void ResolveEvent(sf::Event handled_event);

private:
    std::vector<std::shared_ptr<Controllable>> controllable_;
    std::shared_ptr<sf::RenderWindow> managed_window_;
};

#endif