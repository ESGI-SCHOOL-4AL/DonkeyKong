#ifndef ENTITY_H
#define ENTITY_H

#include "pch.h"

enum EntityType {
	player,
	block,
	echelle
};

class Entity {
public:
	Entity() { };
	~Entity() { };
	bool collidesWith(sf::Sprite entity);

public:
	sf::Sprite m_sprite;
	sf::Vector2u m_size;
	sf::Vector2f m_position;
	EntityType m_type;
	bool m_enabled = true;

	// Enemy only
	bool m_bLeftToRight = true;
	int m_times = 0;
};

#endif