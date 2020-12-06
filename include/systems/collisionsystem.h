#pragma once

#include "../lib/entity_manager.h"
#include "./components/positioncomponent.h"
#include "./components/collisioncomponent.h"
#include "./components/texturecomponent.h"
#include "./lib/i_system.h"

class CollisionSystem : public ISystem{
 public:
  void Update();
};
