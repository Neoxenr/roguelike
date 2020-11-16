#pragma once

#include <BearLibTerminal.h>

class Stats {
 private:
  static int count_coins;
  static int count_steps;

 public:
  static int getCountCoins();
  static int getCountSteps();
  static void setCountCoins(const int num);
  static void setCountSteps(const int num);
  void Render();
};
