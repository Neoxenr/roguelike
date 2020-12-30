#pragma once

#include "lib/i_component.h"
#include "systems/statssystem.h"

class StatsComponent : public IComponent {
 private:
  friend class StatsSystem;
  int coins_count, steps_count, levels_completed_count, all_steps_count;

 public:
  StatsComponent() : coins_count(0), steps_count(0), levels_completed_count(0), all_steps_count(0) {}
  int getCoinsCount() const;
  int getStepsCount() const;
  int getLevelsCompletedCount() const;
  int getAllStepsCount() const;
};
