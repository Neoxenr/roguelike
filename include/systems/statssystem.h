#pragma once

#include "lib/i_system.h"
#include "../include/components/statscomponent.h"
#include "../include/components/controlscomponent.h"
#include "../include/components/collisioncomponent.h"

class StatsSystem : public ISystem{
 public:
  void Update();
};
