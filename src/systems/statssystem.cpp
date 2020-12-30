#include "../include/systems/statssystem.h"

#include "../include/components/levelsinformationcomponent.h"
#include "config.h"

void StatsSystem::sortStats() {
  std::vector<int> steps;

  std::fstream file("records/records.txt", std::ios_base::in | std::ios_base::app);

  if (file.is_open()) {
    std::string str;
    while (!file.eof()) {
      std::getline(file, str);
      if (str.find(":") != std::string::npos) {
        steps.push_back(std::stoi(str.substr(str.find(":") + 1, 4)));
      }
    }
    std::sort(steps.begin(), steps.end());
    file.close();
  }
  file.open("records/records.txt");
  if (file.is_open()) {
    for (const auto& elem : steps) {
      file << "Потрачено шагов за игру: " << elem << '\n';
    }
    file.close();
  }
}

void StatsSystem::writeStats() {
  auto player = GetEntityManager()->FindFirstByTag("Player");
  auto level = player->Get<LevelsInformationComponent>();
  auto stats = player->Get<StatsComponent>();

  if (stats->levels_completed_count == levels_count && !stats_is_received) {
    std::ofstream file("records/records.txt", std::ios_base::app);
    if (file.is_open()) {
      file << "Потрачено шагов за игру: " << stats->all_steps_count << '\n';
      file.close();
    }
    sortStats();
    stats_is_received = true;
  }
}

void StatsSystem::playerUpdate() {
  auto player = GetEntityManager()->FindFirstByTag("Player");
  auto stats = player->Get<StatsComponent>();
  auto position = player->Get<PositionComponent>();
  auto controls = player->Get<ControlsComponent>();
  auto collision = player->Get<CollisionComponent>();
  auto level = player->Get<LevelsInformationComponent>();

  if ((level->IsCompleted() && controls->IsEnter()) && stats->levels_completed_count < levels_count) {
    ++stats->levels_completed_count;
    stats->all_steps_count += stats->steps_count;
    stats->steps_count = 0;
    stats->coins_count = 0;
  }

  if (collision->IsBackDoor() && stats->levels_completed_count > 0) {
    --stats->levels_completed_count;
    stats->steps_count = 0;
    stats->coins_count = 0;
  }

  if (collision->IsCoin()) {
    ++stats->coins_count;
  }

  if (controls->IsUp() && !collision->IsUpObject() && position->getY() > 0 && !level->IsCompleted()) {
    ++stats->steps_count;
  }

  if (controls->IsDown() && !collision->IsDownObject() && position->getY() < window_height - 1 &&
      !level->IsCompleted()) {
    ++stats->steps_count;
  }

  if (controls->IsRight() && !collision->IsRightObject() && position->getX() < window_width && !level->IsCompleted()) {
    ++stats->steps_count;
  }

  if (controls->IsLeft() && !collision->IsLeftObject() && position->getX() > 0 && !level->IsCompleted()) {
    ++stats->steps_count;
  }
}

void StatsSystem::Update() {
  playerUpdate();
  writeStats();
}
