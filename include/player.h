#pragma once

#include "coinmanager.h"
#include "controls.h"
#include "stats.h"

class Player {
 private:
  const Controls &control;
  const Ground &ground;
  Stats *stats;
  int player_x;
  int player_y;
  char symbol = '@';

 public:
  Player(const Controls &control, const Ground &ground, Stats *st, int x = 0, int y = 0)
      : control(control), ground(ground), stats(st), player_x(x), player_y(y) {}
  void Render() const;
  void Move();
  void Update();
  void Take(const CoinManager &coins) const;
  bool Is_Coin(const Coin *coin) const;
};
