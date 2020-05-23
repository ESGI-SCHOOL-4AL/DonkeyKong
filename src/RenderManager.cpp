#include "RenderManager.hpp"

RenderManager::RenderManager() { }

RenderManager::RenderManager(std::shared_ptr<sf::RenderWindow> window) { 
    managed_window_ = window;
}

void RenderManager::Render() {
    managed_window_->clear(sf::Color::Black);
    managed_window_->display();
}

RenderManager::~RenderManager() { }