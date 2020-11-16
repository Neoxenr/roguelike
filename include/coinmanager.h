#pragma once

#include <BearLibTerminal.h>

#include <ctime>
#include <vector>

#include "coin.h"

class CoinManager {
 private:
  std::vector<Coin*> coins;
  int count = 0;

 public:
  int getCount() const;
  void setCount(const int num);
  void Create(int x, int y, int sym);
  void Render() const;
  std::vector<Coin*>&getCoins();
};
