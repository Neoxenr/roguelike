#include "controls.h"

bool Controls::Is_Exit() const {
  return is_exit;
}

bool Controls::Is_Up() const {
  return is_up;
}

bool Controls::Is_Down() const {
  return is_down;
}

bool Controls::Is_Right() const {
  return is_right;
}

bool Controls::Is_Left() const {
  return is_left;
}

void Controls::Update() {
  is_exit = false;
  is_up = false;
  is_down = false;
  is_right = false;
  is_left = false;

  while (terminal_has_input()) {
    auto event = terminal_read();

    if (event == TK_UP) is_up = true;

    if (event == TK_DOWN) is_down = true;

    if (event == TK_RIGHT) is_right = true;

    if (event == TK_LEFT) is_left = true;

    if (event == TK_CLOSE) is_exit = true;
  }
}
