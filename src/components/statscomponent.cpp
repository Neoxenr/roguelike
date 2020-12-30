#include "../include/components/statscomponent.h"

int StatsComponent::getCoinsCount() const {
  return coins_count;
}

int StatsComponent::getStepsCount() const {
  return steps_count;
}

int StatsComponent::getLevelsCompletedCount() const {
  return levels_completed_count;
}

int StatsComponent::getAllStepsCount() const {
  return all_steps_count;
}
