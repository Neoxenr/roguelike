#pragma once

#include <BearLibTerminal.h>

#include "../components/collisioncomponent.h"
#include "../components/levelsinformationcomponent.h"
#include "../components/positioncomponent.h"
#include "../components/statscomponent.h"
#include "../components/texturecomponent.h"
#include "../lib/entity_manager.h"
#include "./lib/i_system.h"

class RenderSystem : public ISystem {
 public:
  void Start();
  void Main();
  void Stats();
  void Update();
};
