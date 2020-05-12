#include "EntityManager.hpp"

EntityManager::EntityManager() {
	std::vector<std::shared_ptr<Entity>> entities_;
}


EntityManager::~EntityManager() {
}

std::shared_ptr<Entity> EntityManager::GetPlayer() {
	for (std::shared_ptr<Entity> entity : EntityManager::entities_) {
		if (entity->drawable_ == false) {
			continue;
		}

		if (InstanceOf<Mario>(entity.get())) {
			return entity;
		}
	}

	return nullptr;
}
