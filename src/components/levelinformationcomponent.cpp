#include "../include/components/levelinformationcomponent.h"

bool LevelInformationComponent::IsCompleted() const {
  return level_is_completed;
}

void LevelInformationComponent::setCompleted(bool value) {
  level_is_completed = value;
}
