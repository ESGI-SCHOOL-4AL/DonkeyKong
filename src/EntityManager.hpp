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
		static std::shared_ptr<Entity> GetPlayer();

	public:
		static std::vector<std::shared_ptr<Entity>> entities_;
};

#endif