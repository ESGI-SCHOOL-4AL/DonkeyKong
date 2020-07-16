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
            c->KeyPressed(handled_event);
        }
        break;
    case sf::Event::KeyReleased:
        for (auto c : controllable_)
        {
            c->KeyReleased(handled_event);
        }
        break;
    default:
        break;
    }
}

void EventManager::RegisterControllableEntity(std::shared_ptr<Controllable> controllable)
{
    controllable_.push_back(controllable);
}

EventManager::~EventManager() {}