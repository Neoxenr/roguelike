#pragma once

class Coin {
 private:
  int coin_pos_x;
  int coin_pos_y;
  char sym_of_coin;
  bool coin_is_visited;

 public:
  Coin() : coin_pos_x(1), coin_pos_y(1), sym_of_coin('$'), coin_is_visited(false) {}
  Coin(int x, int y, char sym, bool flag) : coin_pos_x(x), coin_pos_y(y), sym_of_coin(sym), coin_is_visited(flag) {}
  int get_coin_pos_x() const;
  int get_coin_pos_y() const;
  char &get_coin_sym();
  bool &get_coin_mark();
};
