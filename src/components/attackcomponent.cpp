#include "../include/components/attackcomponent.h"

void AttackComponent::setAttack(bool flag) {
  is_attack = flag;
}

bool AttackComponent::IsAttack() const {
  return is_attack;
}
