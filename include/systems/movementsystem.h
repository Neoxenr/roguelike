#pragma once

#include "../lib/entity_manager.h"
#include "./lib/i_system.h"
#include "./components/controlscomponent.h"
#include "./components/positioncomponent.h"
#include "./components/collisioncomponent.h"

class MovementSystem : public ISystem {
 public:
  void Update();
};
