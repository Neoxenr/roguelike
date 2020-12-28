#pragma once

#include <fstream>
#include <map>
#include <string>
#include <utility>

#include "ireader.h"

class LevelReader : public IReader {
 private:
  std::ifstream file;
  std::map<std::pair<std::string, std::pair<int, int>>, char> data;

 public:
  LevelReader();
  void readLevel(const std::string level_name);
  const std::map<std::pair<std::string, std::pair<int, int>>, char>& getData();
};
