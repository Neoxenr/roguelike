#pragma once

#include <BearLibTerminal.h>

#include "../lib/entity_manager.h"
#include "./components/controlscomponent.h"
#include "./lib/i_system.h"

class ControlsSystem : public ISystem {
 public:
  void Update();
};
