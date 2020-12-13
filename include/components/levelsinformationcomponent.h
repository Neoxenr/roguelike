#pragma once

#include "../include/systems/levelsystem.h"
#include "../lib/i_component.h"

class LevelsInformationComponent : public IComponent {
 private:
  friend class LevelSystem;
  bool is_created;
  bool is_completed;
  bool is_init;

 public:
  LevelsInformationComponent() : is_created(false), is_completed(false), is_init(false) {}
  bool IsCompleted() const;
  bool IsCreated() const;
  bool IsInit() const;
  void setCompleted(bool value);
};
