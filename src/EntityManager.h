#ifndef ENTITY_MANAGER_H
#define ENTITY_MANAGER_H

#include <memory>
#include <vector>

#include "Entity.h"
#include "InstanceOfHelper.h"
// Add Mario Class

class EntityManager {
	public:
		EntityManager();
		~EntityManager();
		static std::shared_ptr<Entity> GetPlayer();

	public:
		static std::vector<std::shared_ptr<Entity>> entities_;
};

#endif