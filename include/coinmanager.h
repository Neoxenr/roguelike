#pragma once

#include <BearLibTerminal.h>

#include <ctime>
#include <vector>

#include "coin.h"
#include "ground.h"

class CoinManager {
 private:
  std::vector<Coin *> coins;
  const Ground &ground;
  int count;

 public:
  explicit CoinManager(const Ground &o) : ground(o) {}
  void Generate_Count();
  int GetCount() const;
  int Generate_Pos_X() const;
  int Generate_Pos_Y() const;
  void Create();
  void Render() const;
  const std::vector<Coin*>&GetCoins() const;
  ~CoinManager();
};
