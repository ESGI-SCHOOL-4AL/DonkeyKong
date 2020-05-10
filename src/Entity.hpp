#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <vector>
// #include <memory>
#include <SFML/Graphics.hpp>

#include "EntitiesData.hpp"
#include "Game.hpp"

#define GRAVITY 40.f

class Entity {
public:
	Entity() { };
	~Entity() { };
	bool CollidesWith(sf::Sprite entity);
	bool WillCollide(sf::Sprite entity, sf::Vector2f newPos);
	void Update(Game* game, sf::Time elapsedTime);

public:
	sf::Sprite sprite_;
	sf::Vector2u size_;
	sf::Vector2f position_;
	sf::Vector2f velocity_;
	bool drawable_;
	bool gravity_;
};

#endif