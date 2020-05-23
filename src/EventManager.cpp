#include "EventManager.hpp"

EventManager::EventManager() { }

EventManager::EventManager(std::shared_ptr<sf::RenderWindow> window) {
    managed_window_ = window;
}

void EventManager::ResolveEvent(sf::Event handled_event) {
    switch (handled_event.type) {
        case sf::Event::Closed:
            managed_window_->close();
            break;
        
        default:
            break;
    }
}

EventManager::~EventManager() { }