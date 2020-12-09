#pragma once

#include "lib/i_component.h"
#include "systems/movementsystem.h"

class PositionComponent : public IComponent {
 private:
  friend class MovementSystem;
  int x, y;

 public:
  PositionComponent(const int _x, const int _y) : x(_x), y(_y) {}
  int getX() const;
  int getY() const;
};
