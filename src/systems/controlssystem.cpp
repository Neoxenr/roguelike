#include "../include/systems/controlssystem.h"

void ControlsSystem::Update() {
  auto elem = GetEntityManager()->FindFirstByTag("Player");

  elem->Get<ControlsComponent>()->is_up = false;
  elem->Get<ControlsComponent>()->is_down = false;
  elem->Get<ControlsComponent>()->is_right = false;
  elem->Get<ControlsComponent>()->is_left = false;
  elem->Get<ControlsComponent>()->is_enter = false;
  elem->Get<ControlsComponent>()->is_exit = false;

  while (terminal_has_input()) {
    auto event = terminal_read();

    if (event == TK_UP) elem->Get<ControlsComponent>()->is_up = true;

    if (event == TK_DOWN) elem->Get<ControlsComponent>()->is_down = true;

    if (event == TK_RIGHT) elem->Get<ControlsComponent>()->is_right = true;

    if (event == TK_LEFT) elem->Get<ControlsComponent>()->is_left = true;

    if (event == TK_ENTER) elem->Get<ControlsComponent>()->is_enter = true;

    if (event == TK_CLOSE) elem->Get<ControlsComponent>()->is_exit = true;
  }
}
