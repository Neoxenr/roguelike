#pragma once

#include "../include/systems/attacksystem.h"
#include "../lib/i_component.h"

class HealthComponent : public IComponent {
 private:
  friend class AttackSystem;
  int health;

 public:
  explicit HealthComponent(const int _health) : health(_health) {}
  int getHealth() const;
};
