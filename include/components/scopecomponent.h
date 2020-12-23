#pragma once

#include "lib/i_component.h"

class ScopeComponent : public IComponent {
 private:
  float x_min, x_max, y_min, y_max;
  bool is_next = true;
  bool is_back = false;

 public:
  ScopeComponent(const float xmin, const float xmax, const float ymin, const float ymax)
      : x_min(xmin), x_max(xmax), y_min(ymin), y_max(ymax) {}
  float getXMin() const;
  float getXMax() const;
  float getYMin() const;
  float getYMax() const;
  bool IsNext() const;
  bool IsBack() const;
  void setNext(bool flag);
  void setBack(bool flag);
};
