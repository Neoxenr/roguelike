#include "../include/systems/rendersystem.h"

void RenderSystem::Stats() {
  auto player = GetEntityManager()->FindFirstByTag("Player");
  terminal_printf(25, 9, "[color=lime]Поздравляем, вы прошли уровень![/color]");
  terminal_printf(23, 11, "[color=lime]Собрано монет:[/color] %s",
                  std::to_string(player->Get<StatsComponent>()->getCoinsCount()).c_str());
  terminal_printf(41, 11, "[color=lime]Сделано шагов:[/color] %s",
                  std::to_string(player->Get<StatsComponent>()->getStepsCount()).c_str());
  terminal_set("0x45: none");
  terminal_printf(15, 13,
                  "[color=lime]Нажмите[/color] [color=violet]Enter[/color] [color=lime]чтобы перейти к следующему "
                  "уровню[/color]");
}

void RenderSystem::Start() {
  terminal_printf(22, 4, "[color=purple]Выберите режим инициализации уровней[/color]");
  terminal_printf(22, 6, "[color=orange]1[/color]. [color=amber]Инициализировать уровни из файлов[/color]");
  terminal_printf(22, 8, "[color=orange]2[/color]. [color=amber]Инициализировать уровни случайно[/color]");

  terminal_printf(27, 12, "[align=center][color=violet]Выберите графический режим[/color]");
  terminal_printf(25, 14, "[color=orange]3[/color]. [color=lime]Использовать только графику[/color]");
  terminal_printf(25, 16, "[color=orange]4[/color]. [color=lime]Использовать только символы[/color]");
}

void RenderSystem::Main() {
  for (const auto &elem : GetEntityManager()->getEntities()) {
    terminal_printf(elem->Get<PositionComponent>()->getX(), elem->Get<PositionComponent>()->getY(),
                    "[color=%s]%c[/color]", elem->Get<TextureComponent>()->getColor().c_str(),
                    elem->Get<TextureComponent>()->getTexture());
  }
  auto player = GetEntityManager()->FindFirstByTag("Player");
  auto health = player->Get<HealthComponent>();
  terminal_printf(0, 24, "[color=flame]Health:[/color][color=green] %s [/color]",
                  std::to_string(static_cast<int>(health->getHealth())).c_str());
}

void RenderSystem::Update() {
  auto player = GetEntityManager()->FindFirstByTag("Player");
  auto controls = player->Get<ControlsComponent>();
  auto collision = player->Get<CollisionComponent>();
  auto level = player->Get<LevelsInformationComponent>();

  if ((!controls->IsOne() && !controls->IsTwo()) || (!controls->IsThree() && !controls->IsFour())) {
    Start();
  }
  if (level->IsCreated() && !level->IsCompleted() && (controls->IsThree() || controls->IsFour())) {
    Main();
  }
  if (level->IsCompleted()) {
    Stats();
  }
}
