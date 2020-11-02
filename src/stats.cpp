#include "stats.h"

int &Stats::get_count_coins() {
  return count_coins;
}

int &Stats::get_count_steps() {
  return count_steps;
}

void Stats::Render() {
  std::string str1 = std::to_string(get_count_coins());
  std::string str2 = std::to_string(get_count_steps());
  terminal_printf(0, 24, "Coins: [color=green]%s[/color]", str1.c_str());
  terminal_printf(10, 24, "Steps: [color=purple]%s[/color]", str2.c_str());
}
