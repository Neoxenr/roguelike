#pragma once

#include "../include/components/healthcomponent.h"
#include "../include/components/collisioncomponent.h"
#include "../include/lib/i_system.h"

class AttackSystem : public ISystem {
 public:
  void Update();
};
