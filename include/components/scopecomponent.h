#pragma once

#include "lib/i_component.h"

class ScopeComponent : public IComponent {
 private:
  float x_min, x_max;
  bool is_next = true;
  bool is_back = false;

 public:
  ScopeComponent(const float x_min, const float x_max) : x_min(x_min), x_max(x_max) {}
  float getXMin() const;
  float getXMax() const;
  bool IsNext() const;
  bool IsBack() const;
  void setNext(bool flag);
  void setBack(bool flag);
};
