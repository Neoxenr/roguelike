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

bool CollisionComponent::IsEnemy() const {
  return is_enemy;
}

bool CollisionComponent::IsNextDoor() const {
  return is_next_door;
}

bool CollisionComponent::IsBackDoor() const {
  return is_back_door;
}

void CollisionComponent::SetNextDoor(bool value) {
  is_next_door = value;
}
void CollisionComponent::SetBackDoor(bool value) {
  is_back_door = value;
}
