#include <lib/entity.h>
#include <lib/entity_manager.h>

#include <algorithm>
#include <iostream>
#include <memory>

Entity* EntityManager::CreateEntity() {
  auto entity = new Entity();
  entity->id = ++last_entity_id;
  entities.push_back(std::unique_ptr<Entity>(entity));
  return entity;
}

void EntityManager::DeleteEntity(size_t id) {
  auto iter =
      std::remove_if(entities.begin(), entities.end(), [id](const auto& entity) { return entity->GetId() == id; });
  entities.erase(iter, entities.end());
}

EntityManager::~EntityManager() {
  entities.clear();
}

void EntityManager::RemoveEntities() {
  entities.clear();
}

Entity* EntityManager::FindFirstByTag(const std::string& tag) {
  for (auto& entity : entities) {
    if (entity->tag == tag) return entity.get();
  }
  return nullptr;
}

const std::vector<std::unique_ptr<Entity>>& EntityManager::getEntities() {
  return entities;
}

std::vector<size_t> EntityManager::getAllId() {
  std::vector<size_t> all_id;
  for (const auto& elem : entities) {
    all_id.push_back(elem->GetId());
  }
  return all_id;
}

size_t EntityManager::getLastEntityId() const {
  return last_entity_id;
}
