#include <BearLibTerminal.h>

#include "coinmanager.h"
#include "player.h"

int main() {
  terminal_open();
  terminal_refresh();

  Ground ground;
  Controls controls;
  Stats stats;
  Player player(controls, ground, &stats);
  CoinManager coins(ground);
  coins.Create();

  while (true) {
    terminal_clear();

    controls.Update();

    if (controls.Is_Exit()) break;

    coins.Render();
    player.Update();
    player.Take(coins);
    stats.Render();

    terminal_refresh();
  }
  terminal_close();
}
