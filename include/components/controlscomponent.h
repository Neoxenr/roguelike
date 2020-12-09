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
  bool is_exit;

 public:
  ControlsComponent()
      : is_up(false), is_down(false), is_right(false), is_left(false), is_enter(false), is_exit(false) {}
  bool IsUp() const;
  bool IsDown() const;
  bool IsRight() const;
  bool IsLeft() const;
  bool IsEnter() const;
  bool IsExit() const;
};
