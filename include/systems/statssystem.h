#pragma once

#include "../include/components/collisioncomponent.h"
#include "../include/components/controlscomponent.h"
#include "../include/components/statscomponent.h"
#include "lib/i_system.h"

class StatsSystem : public ISystem {
 public:
  void Update();
};
