#include <lib/entity_manager.h>
#include <lib/i_system.h>

bool ISystem::Filter(Entity* entity) const {
  return true;
}
EntityManager* ISystem::GetEntityManager() {
  return entityManager;
}
