#pragma once

#include "lib/i_component.h"
#include "systems/collisionsystem.h"

class CollisionComponent : public IComponent {
 private:
  friend class CollisionSystem;
  bool up_object;
  bool down_object;
  bool right_object;
  bool left_object;
  bool is_enemy;
  bool is_coin;
  bool is_next_door = false;
  bool is_back_door = false;

 public:
  bool IsUpObject() const;
  bool IsDownObject() const;
  bool IsRightObject() const;
  bool IsLeftObject() const;
  bool IsCoin() const;
  bool IsEnemy() const;
  bool IsNextDoor() const;
  bool IsBackDoor() const;
  void SetNextDoor(bool value);
  void SetBackDoor(bool value);
};
