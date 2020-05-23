#ifndef RENDER_MANAGER_HPP
#define RENDER_MANAGER_HPP

#include <memory>
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

class RenderManager {
    public:
        RenderManager();
        RenderManager(std::shared_ptr<sf::RenderWindow> window);
        ~RenderManager();
        void Render();
    
    private:
        std::shared_ptr<sf::RenderWindow> managed_window_;
};

#endif