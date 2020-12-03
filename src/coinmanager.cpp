#include "coinmanager.h"

void CoinManager::Create(int x, int y, int sym) {
  coins.push_back(new Coin(x, y, sym));
  ++count;
}

void CoinManager::Render() const {
  for (int i = 0; i < count; ++i)
    terminal_printf(coins[i]->getPosX(), coins[i]->getPosY(), "[color=yellow]%c[/color]", coins[i]->getSym());
}

int CoinManager::getCount() const {
  return count;
}

void CoinManager::setCount(const int num) {
  count = num;
}

std::vector<Coin*>& CoinManager::getCoins() {
  return coins;
}
