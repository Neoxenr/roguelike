#pragma once

#include <memory>

class Context;
class EntityManager;
class Entity;

class ISystem {
  friend class SystemManager;
  EntityManager* entityManager;

 public:
  virtual ~ISystem() = default;

 protected:
  virtual void Update() = 0;
  virtual bool Filter(Entity* entity) const;
  EntityManager* GetEntityManager();
};
