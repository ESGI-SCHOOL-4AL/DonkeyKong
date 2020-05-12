#include "Game.hpp"

const float Game::playerSpeed = 100.f;
const sf::Time Game::timePerFrame = sf::seconds(1.f / 60.f);

Game::Game()
	: window_(sf::VideoMode(840, 600), "Donkey Kong 1981", sf::Style::Close)
	, texture_()
	, player_()
	, font_()
	, statistics_text_()
	, statistics_update_time_()
	, statistics_num_frames_(0)
	, is_moving_up_(false)
	, is_moving_down_(false)
	, is_moving_right_(false)
	, is_moving_left(false)
{
	window_.setFramerateLimit(160);

	entities_manager_ = EntityManager();
	block_generator_ = BlockGenerator();
	platform_blocks_ = std::vector<Block>();

	// Draw blocks

	for (int i = 1; i <= BLOCK_COUNT_Y; i++) {
		std::vector<Block> current_platform = block_generator_.GeneratePlatform(BLOCK_COUNT_X, SPACING_FROM_WINDOW, BLOCK_SPACE * i);
		for (Block block : current_platform) { 
			platform_blocks_.push_back(block);
			std::shared_ptr<Entity> shared_block = std::make_shared<Entity>();
			*shared_block = block;
			entities_manager_.entities_.push_back(shared_block);
		}
	}

	// Draw Echelles
	std::cout << "Test 1" << std::endl; 

	for (int i = 0; i < LADDER_COUNT; i++) {
		ladder_[i].setTexture(texture_ladder_);
		ladder_[i].setPosition(100.f + 70.f * (i + 1), 0.f + BLOCK_SPACE * (i + 1) + size_block_.y );

		// std::shared_ptr<Entity> se = std::make_shared<Entity>();
		// se->sprite_ = ladder_[i];
		// se->size_ = texture_ladder_.getSize();
		// se->position_ = ladder_[i].getPosition();
		// entities_manager_.entities_.push_back(se);

	}

	// Draw Mario
	std::cout << "Test 2" << std::endl;

	texture_.loadFromFile("Media/Textures/Mario_small_transparent.png"); // Mario_small.png");
	size_mario_ = texture_.getSize();
	player_.setTexture(texture_);
	sf::Vector2f posMario;
	posMario.x = 100.f + 70.f;
	posMario.y = BLOCK_SPACE * 5 - size_mario_.y;

	player_.setPosition(posMario);

	std::shared_ptr<Entity> player = std::make_shared<Entity>();
	player->sprite_ = player_;
	player->size_ = texture_.getSize();
	player->position_ = player_.getPosition();
	player->gravity_ = true;
	entities_manager_.entities_.push_back(player);
	player_entity_ = player;

	// Draw Statistic Font 
	std::cout << "Test 3" << std::endl;

	font_.loadFromFile("Media/Sansation.ttf");
	statistics_text_.setString("Welcome to Donkey Kong 1981");
	statistics_text_.setFont(font_);
	statistics_text_.setPosition(5.f, 5.f);
	statistics_text_.setCharacterSize(10);
}

void Game::Run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	while (window_.isOpen())
	{
		sf::Time elapsedTime = clock.restart();
		timeSinceLastUpdate += elapsedTime;
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;

			ProcessEvents();
			Update(timePerFrame);
		}

		UpdateStatistics(elapsedTime);
		Render();
	}
}

void Game::ProcessEvents()
{
	sf::Event event;
	while (window_.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::KeyPressed:
			HandlePlayerInput(event.key.code, true);
			break;

		case sf::Event::KeyReleased:
			HandlePlayerInput(event.key.code, false);
			break;

		case sf::Event::Closed:
			window_.close();
			break;
		}
	}
}

void Game::Update(sf::Time elapsedTime) {
	sf::Vector2f movement(0.f, 0.f);
	std::cout << "Frame i'm" << std::endl;

	for (auto ladder  : ladder_) {
		if(player_entity_->CollidesWith(ladder)) {
			std::cout << "YES I'M IN !" << std::endl;
			if (is_moving_up_)
				movement.y -= playerSpeed;
			if (is_moving_down_)
				movement.y += playerSpeed;
			break;
		}
	}

	for (int i = 0; i < BLOCK_COUNT_X; i++) {
		for (int j = 0; j < BLOCK_COUNT_Y; j++) {
			auto platform = block_[i][j];
			if(player_entity_->CollidesWith(platform)) {
				if (is_moving_left)
					movement.x -= playerSpeed;
				if (is_moving_right_)
					movement.x += playerSpeed;
				i = BLOCK_COUNT_X;
				break;
			}
		}
	}
	
	if (is_moving_left)
		movement.x -= playerSpeed;
	if (is_moving_right_)
		movement.x += playerSpeed;

	// To send into the hell
	// for (std::shared_ptr<Entity> entity : entities_manager_.entities_) {
	// 	if (entity->drawable_ == false) {
	// 		continue;
	// 	}

	// 	if (entity->m_type != EntityType::player) {
	// 		continue;
	// 	}

	// 	entity->sprite_.move(movement * elapsedTime.asSeconds());
	// }
	
	// player_entity_->sprite_.move(movement * elapsedTime.asSeconds());	
	player_entity_->Update(platform_blocks_, elapsedTime);
}

void Game::Render() {
	window_.clear();
	std::cout << "Render i'm" << std::endl; 
	for (std::shared_ptr<Entity> entity : entities_manager_.entities_) {
		entity.Drawable(window_);
	}

	window_.draw(statistics_text_);
	window_.display();
	std::cout << "Render i'm not" << std::endl; 
}

void Game::UpdateStatistics(sf::Time elapsedTime)
{
	statistics_update_time_ += elapsedTime;
	statistics_num_frames_ += 1;

	if (statistics_update_time_ >= sf::seconds(1.0f))
	{
		statistics_text_.setString(
			"Frames / Second = " + toString(statistics_num_frames_) + "\n" +
			"Time / Update = " + toString(statistics_update_time_.asMicroseconds() / statistics_num_frames_) + "us");

		statistics_update_time_ -= sf::seconds(1.0f);
		statistics_num_frames_ = 0;
	}

	//
	// Handle collision
	//

	if (statistics_update_time_ >= sf::seconds(0.050f))
	{
		// Handle collision weapon enemies
	}
}

void Game::HandlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
	if (key == sf::Keyboard::Up)
		is_moving_up_ = isPressed;
	else if (key == sf::Keyboard::Down)
		is_moving_down_ = isPressed;
	else if (key == sf::Keyboard::Left)
		is_moving_left = isPressed;
	else if (key == sf::Keyboard::Right)
		is_moving_right_ = isPressed;

	if (key == sf::Keyboard::Space)
	{
	}
}
