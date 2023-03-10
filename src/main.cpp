#include <BearLibTerminal.h>

#include "../include/components/collisioncomponent.h"
#include "../include/components/healthcomponent.h"
#include "../include/config.h"
#include "../include/lib/engine.h"
#include "../include/systems/graphicssystem.h"
#include "../include/systems/rendersystem.h"

int main() {
  terminal_open();
  terminal_refresh();

  Engine engine;

  engine.GetSystemManager()->AddSystem<LevelSystem>();
  engine.GetSystemManager()->AddSystem<GraphicsSystem>();
  engine.GetSystemManager()->AddSystem<ControlsSystem>();
  engine.GetSystemManager()->AddSystem<CollisionSystem>();
  engine.GetSystemManager()->AddSystem<MovementSystem>();
  engine.GetSystemManager()->AddSystem<AttackSystem>();
  engine.GetSystemManager()->AddSystem<StatsSystem>();
  engine.GetSystemManager()->AddSystem<RenderSystem>();

  auto player = engine.GetEntityManager()->CreateEntity();

  player->SetTag("Player");
  player->Add<HealthComponent>(std::make_shared<HealthComponent>(100));
  player->Add<PositionComponent>(std::make_shared<PositionComponent>(0, -1));
  player->Add<TextureComponent>(std::make_shared<TextureComponent>(player_texture, player_color));
  player->Add<ControlsComponent>();
  player->Add<CollisionComponent>();
  player->Add<StatsComponent>();
  player->Add<LevelsInformationComponent>();

  while (true) {
    terminal_clear();

    engine.Update();

    if (player->Get<ControlsComponent>()->IsExit()) break;

    terminal_refresh();
  }
  terminal_close();
}
