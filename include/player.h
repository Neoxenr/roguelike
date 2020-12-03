#pragma once

#include "coinmanager.h"
#include "controls.h"
#include "stats.h"

class Player {
 private:
  Controls *control;
  int player_x;
  int player_y;
  char symbol = '@';

 public:
  explicit Player(Controls *control, int x = 0, int y = 0)
      : control(control), player_x(x), player_y(y) {}
  int getPosX() const;
  int getPosY() const;
  void Render() const;
  void Move();
  void Update();
};
