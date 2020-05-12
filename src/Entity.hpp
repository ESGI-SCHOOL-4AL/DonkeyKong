#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <vector>
#include <SFML/Graphics.hpp>

#include "EntitiesData.hpp"

#define GRAVITY 40.f

class Entity {
	public:
		Entity();
		bool CollidesWith(sf::Sprite entity);
		bool WillCollide(sf::Sprite entity, sf::Vector2f newPos);
		void Drawable(sf::RenderWindow window);
		void Update(std::vector<Entity>, sf::Time elapsedTime);

	public:
		sf::Sprite sprite_;
		sf::Vector2u size_;
		sf::Vector2f position_;
		sf::Vector2f velocity_;
		bool drawable_;
		bool gravity_;
};

#endif