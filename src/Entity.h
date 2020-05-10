#ifndef ENTITY_H
#define ENTITY_H

#include <vector>
// #include <memory>
#include <SFML/Graphics.hpp>

#include "EntitiesData.h"
#include "Game.h"

#define GRAVITY 40.f

enum EntityType {
	player,
	block,
	echelle
};

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