#pragma once

#include <fstream>
#include <string>

#include "coinmanager.h"
#include "ireader.h"
#include "wallmanager.h"

class LevelReader : public IReader {
 private:
  std::ifstream file;
  CoinManager *coins;
  WallManager *walls;

 public:
  LevelReader(CoinManager *c, WallManager *w) : coins(c), walls(w) {}
  void readLevel(std::string level_name);
};
