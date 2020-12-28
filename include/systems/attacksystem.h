#pragma once

#include "../include/components/healthcomponent.h"
#include "../include/components/collisioncomponent.h"
#include "../include/components/attackcomponent.h"
#include "../include/components/scopecomponent.h"
#include "../include/lib/i_system.h"

class AttackSystem : public ISystem {
 public:
  void Update();
};
