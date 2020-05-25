#include "Game.hpp"

Game::Game() {
    main_window_ = std::make_shared<sf::RenderWindow>();
    main_window_->create(sf::VideoMode(MAIN_WINDOW_LENGHT, MAIN_WINDOW_HEIGHT), mainWindowName, sf::Style::Close);
    event_manager_ = EventManager(main_window_);
    render_manager_ = RenderManager(main_window_);
    level_generator_ = LevelGenerator();
    game_objects_ = level_generator_.GenerateLevel();

}

void Game::Run() {
    
    while(main_window_->isOpen()) {
        sf::Event popped_event;

        while(main_window_->pollEvent(popped_event)) {
            event_manager_.ResolveEvent(popped_event);
        }

        render_manager_.Render(game_objects_);

    }

}

Game::~Game() { }