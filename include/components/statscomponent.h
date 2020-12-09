#pragma once

#include "lib/i_component.h"
#include "systems/statssystem.h"

class StatsComponent : public IComponent {
 private:
  friend class StatsSystem;
  int coins_count, steps_count;

 public:
  StatsComponent() : coins_count(0), steps_count(0) {}
  int getCoinsCount() const;
  int getStepsCount() const;
};
