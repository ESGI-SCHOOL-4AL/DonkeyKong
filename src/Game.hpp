#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>

#include "EventManager.hpp"
#include "RenderManager.hpp"
#include "LevelGenerator.hpp"

#define MAIN_WINDOW_LENGHT 840
#define MAIN_WINDOW_HEIGHT 600

class Game
{
public:
    Game();
    ~Game();
    void Run();

private:
    const char *mainWindowName = "Donkey Kong 1981";
    std::shared_ptr<sf::RenderWindow> main_window_;
    std::shared_ptr<EventManager> event_manager_;
    RenderManager render_manager_;
    LevelGenerator level_generator_;
    std::vector<std::shared_ptr<Entity>> game_objects_;
};

#endif