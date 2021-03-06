#ifndef RENDER_MANAGER_HPP
#define RENDER_MANAGER_HPP

#include <memory>
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

#include "Entity.hpp"

class RenderManager
{
public:
    RenderManager();
    RenderManager(std::shared_ptr<sf::RenderWindow> window);
    ~RenderManager();
    void Update(std::vector<std::shared_ptr<Entity>> entities);
    void Render(std::vector<std::shared_ptr<Entity>> entities);

private:
    std::shared_ptr<sf::RenderWindow> managed_window_;
};

#endif