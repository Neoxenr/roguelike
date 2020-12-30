#pragma once

#include "lib/i_component.h"

class AttackComponent : public IComponent {
 private:
  bool is_attack;

 public:
  explicit AttackComponent(bool flag) : is_attack(flag) {}
  bool IsAttack() const;
  void setAttack(bool flag);
};
