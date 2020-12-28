#pragma once

#include <fstream>
#include <algorithm>

#include "../include/components/collisioncomponent.h"
#include "../include/components/controlscomponent.h"
#include "../include/components/statscomponent.h"
#include "lib/i_system.h"

class StatsSystem : public ISystem {
 private:
  bool stats_is_received = false;
 public:
  void sortStats();
  void writeStats();
  void playerUpdate();
  void Update();
};
