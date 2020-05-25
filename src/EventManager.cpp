#include "EventManager.hpp"

EventManager::EventManager() {}

EventManager::EventManager(std::shared_ptr<sf::RenderWindow> window)
{
    managed_window_ = window;
}

void EventManager::ResolveEvent(sf::Event handled_event)
{
    switch (handled_event.type)
    {
    case sf::Event::Closed:
        managed_window_->close();
        break;
    case sf::Event::KeyPressed:
        for (auto c : controllable_)
        {
            c->Move(handled_event);
        }
        break;
    default:
        break;
    }
}

void EventManager::RegisterControllableEntity(Controllable *controllable)
{
    controllable_.push_back(controllable);
}

EventManager::~EventManager() {}