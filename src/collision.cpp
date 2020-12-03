#include "collision.h"

bool Collision::IsCoin(const Coin* coin) const {
  return coin->getPosX() == player.getPosX() && coin->getPosY() == player.getPosY();
}

void Collision::passAndTake() const {
  for (int i = 0; i < coins->getCount(); i++)
    if (IsCoin(coins->getCoins()[i])) {
      coins->setCount(coins->getCount() - 1);
      Stats::setCountCoins(Stats::getCountCoins() + 1);
      delete coins->getCoins()[i];
      coins->getCoins()[i] = nullptr;
      auto it = coins->getCoins().begin() + i;
      coins->getCoins().erase(it);
    }
}

void Collision::notPassWall() const {
  for (int i = 0; i < walls->getCount(); i++) {
    if (walls->getWalls()[i]->getPosX() - player.getPosX() == 1 &&
        walls->getWalls()[i]->getPosY() == player.getPosY()) {
      control->Is_Right() = false;
    }
    if (player.getPosX() - walls->getWalls()[i]->getPosX() == 1 &&
        walls->getWalls()[i]->getPosY() == player.getPosY()) {
      control->Is_Left() = false;
    }
    if (player.getPosY() - walls->getWalls()[i]->getPosY() == 1 &&
        walls->getWalls()[i]->getPosX() == player.getPosX()) {
      control->Is_Up() = false;
    }
    if (walls->getWalls()[i]->getPosY() - player.getPosY() == 1 &&
        walls->getWalls()[i]->getPosX() == player.getPosX()) {
      control->Is_Down() = false;
    }
  }
}
