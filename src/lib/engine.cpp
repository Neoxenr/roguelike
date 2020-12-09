#include <lib/engine.h>

void Engine::Update() {
  systemManager->Update();
}
Engine::Engine()
    : entityManager(std::make_unique<EntityManager>()),
      systemManager(std::make_unique<SystemManager>(entityManager.get())) {}

EntityManager* Engine::GetEntityManager() {
  return entityManager.get();
}
SystemManager* Engine::GetSystemManager() {
  return systemManager.get();
}
