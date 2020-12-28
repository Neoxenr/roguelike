#pragma once

#include "../lib/entity_manager.h"
#include "./components/collisioncomponent.h"
#include "./components/controlscomponent.h"
#include "./components/positioncomponent.h"
#include "./lib/i_system.h"

class MovementSystem : public ISystem {
 public:
  void Update();
  void playerUpdate();
  void enemiesUpdate();
};
