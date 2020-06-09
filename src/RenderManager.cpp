#include "RenderManager.hpp"

RenderManager::RenderManager() {}

RenderManager::RenderManager(std::shared_ptr<sf::RenderWindow> window)
{
    managed_window_ = window;
}

void RenderManager::Render(std::vector<std::shared_ptr<Entity>> entities)
{
    managed_window_->clear(sf::Color::Black);

    for (std::shared_ptr<Entity> &entity : entities)
    {
        entity->Draw(managed_window_);
    }

    managed_window_->display();
}

RenderManager::~RenderManager() {}