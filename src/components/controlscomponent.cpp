#include "../include/components/controlscomponent.h"

bool ControlsComponent::IsUp() const {
  return is_up;
}

bool ControlsComponent::IsDown() const {
  return is_down;
}

bool ControlsComponent::IsRight() const {
  return is_right;
}

bool ControlsComponent::IsLeft() const {
  return is_left;
}

bool ControlsComponent::IsEnter() const {
  return is_enter;
}

bool ControlsComponent::IsExit() const {
  return is_exit;
}
