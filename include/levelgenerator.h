#pragma once

#include <ctime>
#include <map>
#include <string>
#include <utility>

#include "config.h"

class LevelGenerator {
 private:
  std::map<std::pair<std::string, std::pair<int, int>>, char> data;

 public:
  LevelGenerator();
  void generateLevel(const std::string level_name);
  const std::map<std::pair<std::string, std::pair<int, int>>, char>& getData();
};
