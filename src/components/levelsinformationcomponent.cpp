#include "../include/components/levelsinformationcomponent.h"

bool LevelsInformationComponent::IsCreated() const {
  return is_created;
}

bool LevelsInformationComponent::IsCompleted() const {
  return is_completed;
}

void LevelsInformationComponent::setCompleted(bool value) {
    is_completed = value;
}
