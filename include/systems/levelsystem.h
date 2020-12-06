#pragma once

#include <fstream>
#include <map>
#include <string>
#include <utility>
#include <vector>

#include "../components/positioncomponent.h"
#include "../components/statscomponent.h"
#include "../components/texturecomponent.h"
#include "../components/levelinformationcomponent.h"
#include "../include/levelreader.h"
#include "../lib/entity_manager.h"
#include "./lib/i_system.h"

class LevelSystem : public ISystem {
 private:
  bool is_respawned;
  std::vector<std::string> level_names;

 public:
  LevelSystem() : is_respawned(false), level_names({"level1.txt", "level2.txt"}) {}
  void Create(const std::string name);
  void Change();
  void Clear();
  void Update();
};
