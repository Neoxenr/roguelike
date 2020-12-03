#include "stats.h"

int Stats::getCountCoins() {
  return count_coins;
}

int Stats::getCountSteps() {
  return count_steps;
}

void Stats::setCountCoins(const int num) {
  count_coins = num;
}

void Stats::setCountSteps(const int num) {
  count_steps = num;
}

void Stats::Render() {
  terminal_printf(0, 24, "Coins: [color=green]%s[/color]", std::to_string(getCountCoins()).c_str());
  terminal_printf(10, 24, "Steps: [color=purple]%s[/color]", std::to_string(getCountSteps()).c_str());
}

int Stats::count_coins = 0;

int Stats::count_steps = 0;
