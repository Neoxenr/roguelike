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
  bool &Is_Up();
  bool &Is_Down();
  bool &Is_Right();
  bool &Is_Left();
  void Update();
};
