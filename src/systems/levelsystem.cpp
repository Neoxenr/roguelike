#include "../include/systems/levelsystem.h"

#include <iostream>

void LevelSystem::Create(const std::string name) {
  LevelReader levelReader;

  levelReader.readLevel(name);

  for (auto& elem : levelReader.getData()) {
    if (elem.first.first == name) {
      auto temp = GetEntityManager()->CreateEntity();
      if (elem.second == '$') {
        temp->SetTag("Coin");
        temp->Add<TextureComponent>(std::make_shared<TextureComponent>('$', "yellow"));
        temp->Add<PositionComponent>(
            std::make_shared<PositionComponent>(elem.first.second.first, elem.first.second.second));
      } else if (elem.second == '#') {
        temp->SetTag("Wall");
        temp->Add<TextureComponent>(std::make_shared<TextureComponent>('#', "orange"));
        temp->Add<PositionComponent>(
            std::make_shared<PositionComponent>(elem.first.second.first, elem.first.second.second));
      } else if (elem.second == '>') {
        temp->SetTag("Door");
        temp->Add<TextureComponent>(std::make_shared<TextureComponent>('>', "purple"));
        temp->Add<PositionComponent>(
            std::make_shared<PositionComponent>(elem.first.second.first, elem.first.second.second));
      }
    }
  }
  is_respawned = true;
}

void LevelSystem::Clear() {
  std::vector<size_t> temp = GetEntityManager()->getAllId();
  for (size_t i = 1; i < temp.size(); i++) {
    GetEntityManager()->DeleteEntity(temp.at(i));
  }
}

void LevelSystem::Change() {
  level_names.erase(level_names.begin());
  is_respawned = false;
}

void LevelSystem::Update() {
  auto player = GetEntityManager()->FindFirstByTag("Player");
  auto check = player->Get<CollisionComponent>();
  auto level = player->Get<LevelInformationComponent>();
  auto control = player->Get<ControlsComponent>();

  if (!level_names.empty()) {
    if (!is_respawned) {
      Create(level_names.at(0));
    }

    if (level->IsCompleted()) {
      Clear();
      if (control->IsEnter()) {
        Change();
        if (!level_names.empty()) {  // временная затычка на проверку конца количества уровней
          level->setCompleted(0);
        }
      }
    }
  }
}
