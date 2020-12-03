#include "wallmanager.h"

void WallManager::Create(int x, int y, int sym) {
  walls.push_back(new Wall(x, y, sym));
  ++count;
}

void WallManager::Render() const {
  for (int i = 0; i < count; ++i)
    terminal_printf(walls[i]->getPosX(), walls[i]->getPosY(), "[color=orange]%c[/color]", walls[i]->getSym());
}

int WallManager::getCount() const {
  return count;
}

std::vector<Wall *> &WallManager::getWalls() {
  return walls;
}
