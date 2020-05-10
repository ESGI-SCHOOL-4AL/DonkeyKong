#include "EntityManager.hpp"

std::vector<std::shared_ptr<Entity>> EntityManager::entities_;

EntityManager::EntityManager() {
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
