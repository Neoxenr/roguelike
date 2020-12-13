#pragma once

#include <ctime>
#include <fstream>
#include <map>
#include <string>
#include <utility>
#include <vector>

#include "../components/levelsinformationcomponent.h"
#include "../components/positioncomponent.h"
#include "../components/statscomponent.h"
#include "../components/texturecomponent.h"
#include "../include/levelgenerator.h"
#include "../include/levelreader.h"
#include "../lib/entity_manager.h"
#include "./lib/i_system.h"

class LevelSystem : public ISystem {
 private:
  std::map<std::pair<std::string, std::pair<int, int>>, char> data;
  LevelReader levelReader;
  LevelGenerator levelGenerator;
  size_t level_id;
  bool data_is_received;

 public:
  LevelSystem() : level_id(0), data_is_received(false) {}
  std::pair<int, int> FindDoor(const std::string level_name);
  void Create(const std::string level_name);
  void getDataForLevels(const bool mode);
  void Change();
  void Clear();
  void Update();
};
