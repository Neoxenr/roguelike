#pragma once

#include "player.h"
#include "wallmanager.h"

class Collision {
 private:
  const Player &player;
  WallManager *walls;
  CoinManager *coins;
  Controls *control;

 public:
  Collision(const Player &p, WallManager *w, CoinManager *c, Controls *con)
      : player(p), walls(w), coins(c), control(con) {}
  bool IsCoin(const Coin *coin) const;
  void passAndTake() const;
  void notPassWall() const;
};
