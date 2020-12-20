#include "../include/systems/graphicssystem.h"

void GraphicsSystem ::Update() {
  auto player = GetEntityManager()->FindFirstByTag("Player");
  auto controls = player->Get<ControlsComponent>();

  if (controls->IsThree()) {
    terminal_set("0x23: Sprites/wall.png, align=center");
    terminal_set("0x24: Sprites/coin.png, align=center");
    terminal_set("0x40: Sprites/player.png, align=center");
    terminal_set("0x45: Sprites/enemy.png, align=center");
    terminal_set("0x3E: Sprites/door.png, align=center");
  }
  if (controls->IsFour()) {
    terminal_set("0x23: none");
    terminal_set("0x24: none");
    terminal_set("0x40: none");
    terminal_set("0x45: none");
    terminal_set("0x3E: none");
  }
}
