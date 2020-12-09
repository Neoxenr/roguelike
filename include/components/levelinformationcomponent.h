#pragma once

#include "../include/systems/levelsystem.h"
#include "../lib/i_component.h"

class LevelInformationComponent : public IComponent {
 private:
  friend class LevelSystem;
  bool level_is_completed;

 public:
  LevelInformationComponent() : level_is_completed(false) {}
  bool IsCompleted() const;
  void setCompleted(bool value);
};
