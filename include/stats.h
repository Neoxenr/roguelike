#pragma once

#include <BearLibTerminal.h>

class Stats {
 private:
  int count_coins;
  int count_steps;

 public:
  Stats() : count_coins(0), count_steps(0) {}
  int &get_count_coins();
  int &get_count_steps();
  void Render();
};
