#include "player.h"

void Player::Render() const {
  terminal_put(player_x, player_y, symbol);
}

void Player::Move() {
  if (control.Is_Up() && player_y > 0) {
    player_y -= 1;
    ++stats->get_count_steps();
  }
  if (control.Is_Down() && player_y < ground.Ground_Y() - 2) {
    player_y += 1;
    ++stats->get_count_steps();
  }
  if (control.Is_Left() && player_x > 0) {
    player_x -= 1;
    ++stats->get_count_steps();
  }
  if (control.Is_Right() && player_x < ground.Ground_X() - 1) {
    player_x += 1;
    ++stats->get_count_steps();
  }
}

void Player::Update() {
  Move();
  Render();
}

bool Player::Is_Coin(const Coin* coin) const {
  return coin->get_coin_pos_x() == player_x && coin->get_coin_pos_y() == player_y;
}

void Player::Take(const CoinManager& coins) const {
  for (int i = 0; i < coins.GetCount(); i++)
    if (Is_Coin(coins.GetCoins()[i]) && !coins.GetCoins()[i]->get_coin_mark()) {
      coins.GetCoins()[i]->get_coin_sym() = ' ';
      coins.GetCoins()[i]->get_coin_mark() = true;
      ++stats->get_count_coins();
    }
}
