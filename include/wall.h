#pragma once

class Wall {
 private:
  int pos_x;
  int pos_y;
  char sym;
 public:
  Wall(int x, int y, int s) : pos_x(x), pos_y(y), sym(s) {}
  int getPosX() const;
  int getPosY() const;
  char getSym() const;
};
