#include "coinmanager.h"

void CoinManager::Generate_Count() {
  std::srand(static_cast<unsigned int>(std::time(nullptr)));

  count = (std::rand() % 10) + 1;
}

int CoinManager::Generate_Pos_X() const {
  return std::rand() % ground.Ground_X();
}

int CoinManager::Generate_Pos_Y() const {
  return std::rand() % ground.Ground_Y();
}

void CoinManager::Create() {
  Generate_Count();
  for (int i = 0; i < count; ++i) {
    coins.push_back(new Coin(Generate_Pos_X(), Generate_Pos_Y(), '$', false));
  }
}

void CoinManager::Render() const {
  for (int i = 0; i < count; ++i)
    terminal_printf(coins[i]->get_coin_pos_x(), coins[i]->get_coin_pos_y(), "[color=yellow]%c[/color]",
                    coins[i]->get_coin_sym());
}

int CoinManager::GetCount() const {
  return count;
}

const std::vector<Coin*>& CoinManager::GetCoins() const {
  return coins;
}

CoinManager::~CoinManager() {
  for (int i = 0; i < count; ++i) delete coins[i];
}
