#include "coin.h"

int Coin::get_coin_pos_x() const {
  return coin_pos_x;
}

int Coin::get_coin_pos_y() const {
  return coin_pos_y;
}

char& Coin::get_coin_sym() {
  return sym_of_coin;
}

bool & Coin::get_coin_mark() {
  return coin_is_visited;
}
