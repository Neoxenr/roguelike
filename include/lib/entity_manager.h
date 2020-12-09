#pragma once

#include <lib/entity.h>

#include <memory>
#include <string>
#include <vector>

class EntityManager {
 private:
  std::vector<std::unique_ptr<Entity>> entities;
  size_t last_entity_id = 0;

 public:
  Entity* FindFirstByTag(const std::string& tag);
  Entity* CreateEntity();
  const std::vector<std::unique_ptr<Entity>>& getEntities();
  std::vector<size_t> getAllId();
  void DeleteEntity(size_t id);
  void RemoveEntities();
  size_t getLastEntityId() const;
  virtual ~EntityManager();
};
