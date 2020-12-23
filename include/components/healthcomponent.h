#pragma once

#include "../include/systems/attacksystem.h"
#include "../lib/i_component.h"

class HealthComponent : public IComponent {
 private:
  friend class AttackSystem;
  float health;

 public:
  explicit HealthComponent(const int _health) : health(_health) {}
  float getHealth() const;
};
