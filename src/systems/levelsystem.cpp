#include "../include/systems/levelsystem.h"

std::pair<int, int> LevelSystem::FindDoor(const std::string level_name) {
  for (const auto& elem : data) {
    if (elem.first.first == level_name && elem.second == door_texture) {
      return elem.first.second;
    }
  }
  return std::make_pair(0, 0);
}

void LevelSystem::getDataForLevels(const bool mode) {
  if (!data_is_received) {
    if (mode) {
      for (auto i = 0; i < levels_count; i++) {
        levelReader.readLevel("level" + std::to_string(i));
      }
      data = levelReader.getData();
    }
    if (!mode) {
      for (auto i = 0; i < levels_count; i++) {
        levelGenerator.generateLevel("level" + std::to_string(i));
      }
      data = levelGenerator.getData();
    }
    data_is_received = true;
  }
}

void LevelSystem::Change() {
  auto player = GetEntityManager()->FindFirstByTag("Player");
  auto x = player->Get<PositionComponent>()->getX();
  auto y = player->Get<PositionComponent>()->getY();
  player->Delete<PositionComponent>();
  player->Add<PositionComponent>(std::make_shared<PositionComponent>(x, y + 1));

  if (level_id > 0) {
    auto door = FindDoor("level" + std::to_string(level_id - 1));
    auto back_door = GetEntityManager()->CreateEntity();
    back_door->SetTag("BackDoor");
    back_door->Add<TextureComponent>(std::make_shared<TextureComponent>(door_texture, back_door_color));
    back_door->Add<PositionComponent>(std::make_shared<PositionComponent>(door.first, door.second));
  }
}

void LevelSystem::Create(const std::string level_name) {
  for (const auto& elem : data) {
    if (elem.first.first == level_name) {
      auto temp = GetEntityManager()->CreateEntity();
      if (elem.second == coin_texture) {
        temp->SetTag("Coin");
        temp->Add<TextureComponent>(std::make_shared<TextureComponent>(coin_texture, coin_color));
        temp->Add<PositionComponent>(
            std::make_shared<PositionComponent>(elem.first.second.first, elem.first.second.second));
      }
      if (elem.second == wall_texture) {
        temp->SetTag("Wall");
        temp->Add<TextureComponent>(std::make_shared<TextureComponent>(wall_texture, wall_color));
        temp->Add<PositionComponent>(
            std::make_shared<PositionComponent>(elem.first.second.first, elem.first.second.second));
      }
      if (elem.second == door_texture) {
        temp->SetTag("NextDoor");
        temp->Add<TextureComponent>(std::make_shared<TextureComponent>(door_texture, next_door_color));
        temp->Add<PositionComponent>(
            std::make_shared<PositionComponent>(elem.first.second.first, elem.first.second.second));
      }
      if (elem.second == enemy_texture) {
        temp->SetTag("Enemy");
        temp->Add<TextureComponent>(std::make_shared<TextureComponent>(enemy_texture, enemy_color));
        temp->Add<PositionComponent>(
            std::make_shared<PositionComponent>(elem.first.second.first, elem.first.second.second));
        temp->Add<ScopeComponent>(
            std::make_shared<ScopeComponent>(elem.first.second.first - 5, elem.first.second.first + 5,
                                             elem.first.second.second - 3, elem.first.second.second + 3));
        temp->Add<HealthComponent>(std::make_shared<HealthComponent>(100));
        temp->Add<CollisionComponent>();
      }
    }
  }
}

void LevelSystem::Clear() {
  std::vector<size_t> temp = GetEntityManager()->getAllId();
  for (size_t i = 1; i < temp.size(); i++) {
    GetEntityManager()->DeleteEntity(temp.at(i));
  }
}

void LevelSystem::Update() {
  auto player = GetEntityManager()->FindFirstByTag("Player");
  auto check = player->Get<CollisionComponent>();
  auto level = player->Get<LevelsInformationComponent>();
  auto controls = player->Get<ControlsComponent>();

  if (level_id < levels_count) {
    if (!level->is_created) {
      if (controls->IsOne()) {
        getDataForLevels(1);
        Create("level" + std::to_string(level_id));
        Change();
        level->is_created = true;
        level->is_completed = false;
      }
      if (controls->IsTwo()) {
        getDataForLevels(0);
        Create("level" + std::to_string(level_id));
        Change();
        level->is_created = true;
        level->is_completed = false;
      }
    }
    if (check->IsNextDoor()) {
      Clear();
      if (controls->IsEnter()) {
        level->is_created = false;
        check->SetNextDoor(0);
        ++level_id;
      }
    }
    if (check->IsBackDoor()) {
      Clear();
      level->is_created = false;
      check->SetBackDoor(0);
      --level_id;
    }
  }
}
