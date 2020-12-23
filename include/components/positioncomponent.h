#pragma once

#include "lib/i_component.h"
#include "systems/movementsystem.h"

class PositionComponent : public IComponent {
 private:
  friend class MovementSystem;
  float x, y;

 public:
  PositionComponent(const float _x, const float _y) : x(_x), y(_y) {}
  float getX() const;
  float getY() const;
};
