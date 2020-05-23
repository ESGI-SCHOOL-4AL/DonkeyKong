#ifndef EVENT_MANAGER_HPP
#define EVENT_MANAGER_HPP

#include <memory>
#include <SFML/Graphics.hpp>

class EventManager {
    public:
        EventManager();
        EventManager(std::shared_ptr<sf::RenderWindow> window);
        ~EventManager();
        void ResolveEvent(sf::Event handled_event);
    
    private:
        std::shared_ptr<sf::RenderWindow> managed_window_;
    
};

#endif