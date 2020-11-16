#pragma once

#include <BearLibTerminal.h>

#include <vector>

#include "wall.h"

class WallManager {
 private:
  std::vector<Wall*> walls;
  int count = 0;

 public:
  int getCount() const;
  void Create(int x, int y, int sym);
  void Render() const;
  std::vector<Wall*>& getWalls();
};
