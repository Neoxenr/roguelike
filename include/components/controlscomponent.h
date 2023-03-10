#pragma once

#include "lib/i_component.h"
#include "systems/controlssystem.h"

class ControlsComponent : public IComponent {
 private:
  friend class ControlsSystem;
  bool is_up;
  bool is_down;
  bool is_right;
  bool is_left;
  bool is_enter;
  bool is_one;
  bool is_two;
  bool is_three;
  bool is_four;
  bool is_exit;

 public:
  ControlsComponent() : is_one(false), is_two(false), is_three(false), is_four(false) {}
  bool IsUp() const;
  bool IsDown() const;
  bool IsRight() const;
  bool IsLeft() const;
  bool IsEnter() const;
  bool IsOne() const;
  bool IsTwo() const;
  bool IsThree() const;
  bool IsFour() const;
  bool IsExit() const;
};
