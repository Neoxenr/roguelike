#include "../include/systems/rendersystem.h"

void RenderSystem::Stats() {
  auto player = GetEntityManager()->FindFirstByTag("Player");
  auto player_stats = player->Get<StatsComponent>();

  terminal_set("0x45: none");

  terminal_print_ext(0, 10, window_width, window_height, TK_ALIGN_CENTER,
                     "[color=#FFA07A]Поздравляем, вы прошли уровень![/color]");
  terminal_print_ext(
      10, 12, window_width / 2, window_height, TK_ALIGN_CENTER,
      ("[color=#FFA07A]Собрано монет:[/color] " + std::to_string(player_stats->getCoinsCount())).c_str());
  terminal_print_ext(
      window_width / 2, 12, (window_width / 2) - 20, window_height, TK_ALIGN_CENTER,
      ("[color=#FFA07A]Сделано шагов:[/color] " + std::to_string(player_stats->getStepsCount())).c_str());
  terminal_print_ext(0, 14, window_width, window_height, TK_ALIGN_CENTER,
                     "[color=#FFA07A]Нажмите[/color] [color=#FFD700]Enter[/color] [color=#FFA07A]чтобы перейти к "
                     "следующему уровню[/color]");
}

void RenderSystem::Start() {
  terminal_print_ext(0, 4, window_width, window_height, TK_ALIGN_CENTER,
                     "[color=#FFA07A]Выберите режим инициализации уровней[/color]");
  terminal_print_ext(0, 6, window_width, window_height, TK_ALIGN_CENTER,
                     "[color=orange]1[/color]. Инициализировать уровни из файлов");
  terminal_print_ext(0, 8, window_width, window_height, TK_ALIGN_CENTER,
                     "[color=green]2[/color]. Инициализировать уровни случайно");

  terminal_print_ext(0, 12, window_width, window_height, TK_ALIGN_CENTER,
                     "[color=#FFA07A]Выберите графический режим[/color]");
  terminal_print_ext(0, 14, window_width, window_height, TK_ALIGN_CENTER,
                     "[color=yellow]3[/color]. Использовать только графику");
  terminal_print_ext(0, 16, window_width, window_height, TK_ALIGN_CENTER,
                     "[color=purple]4[/color]. Использовать только символы");
}

void RenderSystem::Main() {
  auto player = GetEntityManager()->FindFirstByTag("Player");
  auto player_health = player->Get<HealthComponent>();
  auto player_stats = player->Get<StatsComponent>();
  auto player_position = player->Get<PositionComponent>();
  auto player_texture_ = player->Get<TextureComponent>();

  for (const auto &elem : GetEntityManager()->getEntities()) {
    if (elem->GetTag() != "Player" && elem->GetTag() != "Enemy") {
      auto elem_position = elem->Get<PositionComponent>();
      auto elem_texture = elem->Get<TextureComponent>();
      terminal_printf(elem_position->getX(), elem_position->getY(), "[color=%s]%c[/color]",
                      elem_texture->getColor().c_str(), elem_texture->getTexture());
    }
  }

  for (const auto &id : GetEntityManager()->getAllIdByTag("Enemy")) {
    auto enemy = GetEntityManager()->FindById(id);
    auto enemy_position = enemy->Get<PositionComponent>();
    auto enemy_texture_ = enemy->Get<TextureComponent>();
    terminal_printf(enemy_position->getX(), enemy_position->getY(), "[color=%s]%c[/color]",
                    enemy_texture_->getColor().c_str(), enemy_texture_->getTexture());
  }

  terminal_printf(player_position->getX(), player_position->getY(), "[color=%s]%c[/color]",
                  player_texture_->getColor().c_str(), player_texture_->getTexture());

  terminal_printf(0, 24, "[color=#FFD700]Собранные монеты:[/color] %s",
                  std::to_string(player_stats->getCoinsCount()).c_str());
  terminal_printf(61, 24, "[color=#9370DB]Шагов осталось:[/color] %s",
                  std::to_string(max_steps_count - player_stats->getStepsCount()).c_str());
  terminal_printf(33, 24, "[color=#ADFF2F]Здоровье:[/color] %s", std::to_string(player_health->getHealth()).c_str());
}

void RenderSystem::Lose() {
  terminal_print_ext(0, 12, window_width, window_height, TK_ALIGN_CENTER,
                     "[color=#DC143C]У вас закончилось шаги![/color]");
  terminal_print_ext(0, 10, window_width, window_height, TK_ALIGN_CENTER, "[color=#DC143C]Вы проиграли![/color]");
}

void RenderSystem::Win() {
  terminal_print_ext(0, 10, window_width, window_height, TK_ALIGN_CENTER,
                     "[color=#ADFF2F]Поздравляем, вы прошли все уровни![/color]");

  std::ifstream file("records/records.txt");
  if (file.is_open()) {
    std::string str;
    for (int i = 0; !file.eof(); i++) {
      getline(file, str);
      if (str.find("Потрачено") != std::string::npos) {
        terminal_print_ext(0, 12 + (i * 2), window_width, window_height, TK_ALIGN_CENTER,
                           ("[color=#FFD700]" + std::to_string(i) + ". " + str + "[/color]").c_str());
      }
    }
  }
}

void RenderSystem::Update() {
  auto player = GetEntityManager()->FindFirstByTag("Player");
  auto controls = player->Get<ControlsComponent>();
  auto collision = player->Get<CollisionComponent>();
  auto level = player->Get<LevelsInformationComponent>();
  auto stats = player->Get<StatsComponent>();

  if (stats->getStepsCount() <= max_steps_count) {
    if ((!controls->IsOne() && !controls->IsTwo()) || (!controls->IsThree() && !controls->IsFour())) {
      Start();
    }
    if (level->IsCreated() && !level->IsCompleted() && (controls->IsThree() || controls->IsFour())) {
      Main();
    }
    if (level->IsCompleted() && stats->getLevelsCompletedCount() < levels_count) {
      Stats();
    }
    if (stats->getLevelsCompletedCount() == levels_count) {
      Win();
    }
  } else {
    Lose();
  }
}
