#pragma once

class Coin {
 private:
  int pos_x;
  int pos_y;
  char sym;

 public:
  Coin(int x, int y, char sym) : pos_x(x), pos_y(y), sym(sym) {}
  int getPosX() const;
  int getPosY() const;
  char getSym() const;
};
