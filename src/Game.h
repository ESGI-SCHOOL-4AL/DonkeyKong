#ifndef GAME_H
#define GAME_H

#include <memory>
#include <iostream>

#include "EntityManager.h"
#include "StringHelpers.h"
#include "EntitiesData.h"


class Game {
	public:
		Game();
		~Game() { };
		void Run();

	public:
		sf::Sprite	ladder_[LADDER_COUNT];
		sf::Sprite	block_[BLOCK_COUNT_X][BLOCK_COUNT_Y];

	private:
		void ProcessEvents();
		void Update(sf::Time elapsedTime);
		void Render();

		void UpdateStatistics(sf::Time elapsedTime);
		void HandlePlayerInput(sf::Keyboard::Key key, bool isPressed);

	private:
		static const float		playerSpeed;
		static const sf::Time	timePerFrame;	

		sf::RenderWindow window_;
		sf::Texture	texture_;
		sf::Sprite	player_;
		sf::Font	font_;
		sf::Text	statistics_text_;
		sf::Time	statistics_update_time_;

		std::size_t	statistics_num_frames_;
		bool is_moving_up_;
		bool is_moving_down_;
		bool is_moving_right_;
		bool is_moving_left;

		sf::Texture	texture_ladder_;
		sf::Texture	texture_block_;
		sf::Texture	texture_weapon_;
		sf::Sprite	weapon_;
		sf::Vector2u size_block_;
		sf::Vector2u size_mario_;
		std::shared_ptr<Entity> player_entity_;

};

#endif