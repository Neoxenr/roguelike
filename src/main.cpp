#include <BearLibTerminal.h>

#include "coinmanager.h"
#include "collision.h"
#include "levelreader.h"
#include "player.h"
#include "wallmanager.h"

int main() {
  terminal_open();
  terminal_refresh();

  Controls controls;
  Player player(&controls);
  Stats stats;
  CoinManager coins;
  WallManager walls;
  Collision collision(player, &walls, &coins, &controls);
  LevelReader file(&coins, &walls);

  file.readLevel("level1.txt");

  while (true) {
    terminal_clear();

    controls.Update();

    if (controls.Is_Exit()) break;

    coins.Render();
    walls.Render();
    collision.notPassWall();
    player.Update();
    collision.passAndTake();

    stats.Render();

    terminal_refresh();
  }
  terminal_close();
}
