#include "../include/components/collisioncomponent.h"

bool CollisionComponent::IsUpObject() const {
  return up_object;
}

bool CollisionComponent::IsDownObject() const {
  return down_object;
}

bool CollisionComponent::IsRightObject() const {
  return right_object;
}

bool CollisionComponent::IsLeftObject() const {
  return left_object;
}

bool CollisionComponent::IsCoin() const {
  return is_coin;
}
