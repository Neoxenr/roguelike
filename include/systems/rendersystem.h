#pragma once

#include "./lib/i_system.h"
#include "../lib/entity_manager.h"
#include "../components/positioncomponent.h"
#include "../components/texturecomponent.h"
#include "../components/statscomponent.h"
#include "../components/collisioncomponent.h"
#include "../components/levelinformationcomponent.h"
#include <BearLibTerminal.h>

class RenderSystem : public ISystem{
 public:
  void Main();
  void Stats();
  void Update();
};
