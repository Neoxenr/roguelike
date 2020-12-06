#pragma once

#include <lib/entity_manager.h>
#include <lib/system_manager.h>

#include <memory>
#include <vector>

class Engine {
 private:
  std::unique_ptr<EntityManager> entityManager;
  std::unique_ptr<SystemManager> systemManager;

 public:
  Engine();
  void Update();
  EntityManager* GetEntityManager();
  SystemManager* GetSystemManager();
};
