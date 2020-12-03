#include "player.h"

void Player::Render() const {
  terminal_put(player_x, player_y, symbol);
}

void Player::Move() {
  if (control->Is_Up() && player_y > 0) {
    player_y -= 1;
    Stats::setCountSteps(Stats::getCountSteps() + 1);
  }
  if (control->Is_Down() && player_y < 23) {
    player_y += 1;
    Stats::setCountSteps(Stats::getCountSteps() + 1);
  }
  if (control->Is_Left() && player_x > 0) {
    player_x -= 1;
    Stats::setCountSteps(Stats::getCountSteps() + 1);
  }
  if (control->Is_Right() && player_x < 79) {
    player_x += 1;
    Stats::setCountSteps(Stats::getCountSteps() + 1);
  }
}

void Player::Update() {
  Move();
  Render();
}

int Player::getPosX() const {
  return player_x;
}

int Player::getPosY() const {
  return player_y;
}
