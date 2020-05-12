#ifndef ENTITY_MANAGER_HPP
#define ENTITY_MANAGER_HPP

#include <memory>
#include <vector>

#include "Entity.hpp"
#include "InstanceOfHelper.hpp"
#include "Mario.hpp"

class EntityManager {
	public:
		EntityManager();
		~EntityManager();
		std::shared_ptr<Entity> GetPlayer();

	public:
		std::vector<std::shared_ptr<Entity>> entities_;
};

#endif