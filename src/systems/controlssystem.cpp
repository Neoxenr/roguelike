#include "../include/systems/controlssystem.h"

void ControlsSystem::Update() {
  auto player = GetEntityManager()->FindFirstByTag("Player");
  auto button = player->Get<ControlsComponent>();

  button->is_up = false;
  button->is_down = false;
  button->is_right = false;
  button->is_left = false;
  button->is_enter = false;
  button->is_exit = false;

  while (terminal_has_input()) {
    auto event = terminal_read();

    if (event == TK_UP) button->is_up = true;

    if (event == TK_DOWN) button->is_down = true;

    if (event == TK_RIGHT) button->is_right = true;

    if (event == TK_LEFT) button->is_left = true;

    if (event == TK_ENTER) button->is_enter = true;

    if (event == TK_1 && !button->is_one && !button->is_two) button->is_one = true;

    if (event == TK_2 && !button->is_two && !button->is_one) button->is_two = true;

    if (event == TK_3 && !button->is_three && !button->is_four) button->is_three = true;

    if (event == TK_4 && !button->is_four && !button->is_three) button->is_four = true;

    if (event == TK_CLOSE) button->is_exit = true;
  }
}
