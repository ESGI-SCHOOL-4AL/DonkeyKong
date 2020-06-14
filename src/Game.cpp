#include "Game.hpp"

const sf::Time Game::timePerFrame = sf::seconds(1.f / 60.f);

Game::Game()
{
    main_window_ = std::make_shared<sf::RenderWindow>();
    main_window_->create(sf::VideoMode(MAIN_WINDOW_LENGHT, MAIN_WINDOW_HEIGHT), mainWindowName, sf::Style::Close);
    event_manager_ = std::shared_ptr<EventManager>(new EventManager(main_window_));
    render_manager_ = RenderManager(main_window_);
    level_generator_ = LevelGenerator();
    game_objects_ = level_generator_.GenerateLevel(event_manager_);
    main_window_->setFramerateLimit(60);
}

void Game::Run()
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    while (main_window_->isOpen())
    {
        sf::Time elapsedTime = clock.restart();
        timeSinceLastUpdate += elapsedTime;
        sf::Event popped_event;

        while (timeSinceLastUpdate > timePerFrame)
        {
            timeSinceLastUpdate -= timePerFrame;

            while (main_window_->pollEvent(popped_event))
            {
                event_manager_->ResolveEvent(popped_event);
            }
            render_manager_.Update(game_objects_);
        }
        render_manager_.Render(game_objects_);
    }
}

Game::~Game() {}