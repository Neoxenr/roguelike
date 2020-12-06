#include "../include/systems/rendersystem.h"

void RenderSystem::Stats() {
  auto player = GetEntityManager()->FindFirstByTag("Player");

  terminal_printf(25, 8, "Поздравляем, вы прошли уровень!");

  terminal_printf(23, 10, "Собрано монет: [color=green]%s[/color]",
                  std::to_string(player->Get<StatsComponent>()->getCoinsCount()).c_str());
  terminal_printf(41, 10, "Сделано шагов: [color=purple]%s[/color]",
                  std::to_string(player->Get<StatsComponent>()->getStepsCount()).c_str());

  terminal_printf(15, 12, "Нажмите [color=orange]Enter[/color], чтобы перейти к следующему уровню");
}

void RenderSystem::Main() {
  for (const auto &elem : GetEntityManager()->getEntities()) {
    terminal_printf(elem->Get<PositionComponent>()->getX(), elem->Get<PositionComponent>()->getY(),
                    "[color=%s]%c[/color]", elem->Get<TextureComponent>()->getColor().c_str(),
                    elem->Get<TextureComponent>()->getTexture());
  }
}

void RenderSystem::Update() {
  auto player = GetEntityManager()->FindFirstByTag("Player");
  auto level = player->Get<LevelInformationComponent>();

  if (level->IsCompleted()) {
    Stats();
  } else {
    Main();
  }
}
