#pragma once

#include <BearLibTerminal.h>

class Controls {
 private:
  bool is_exit = false;
  bool is_up = false;
  bool is_down = false;
  bool is_right = false;
  bool is_left = false;

 public:
  bool Is_Exit() const;
  bool Is_Up() const;
  bool Is_Down() const;
  bool Is_Right() const;
  bool Is_Left() const;
  void Update();
};
