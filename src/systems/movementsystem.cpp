#include "../include/systems/movementsystem.h"

#include "../include/components/levelsinformationcomponent.h"

void MovementSystem::playerUpdate() {
  auto player = GetEntityManager()->FindFirstByTag("Player");
  auto controls = player->Get<ControlsComponent>();
  auto collision = player->Get<CollisionComponent>();
  auto position = player->Get<PositionComponent>();
  auto level = player->Get<LevelsInformationComponent>();

  if (controls->IsUp() && !collision->IsUpObject() && position->y > 0 && !level->IsCompleted()) {
    position->y -= 1;
  }

  if (controls->IsDown() && !collision->IsDownObject() && position->y < window_height - 1 && !level->IsCompleted()) {
    position->y += 1;
  }

  if (controls->IsRight() && !collision->IsRightObject() && position->x < window_width && !level->IsCompleted()) {
    position->x += 1;
  }

  if (controls->IsLeft() && !collision->IsLeftObject() && position->x > 0 && !level->IsCompleted()) {
    position->x -= 1;
  }
}

void MovementSystem::enemiesUpdate() {
  for (auto& elem : GetEntityManager()->getEntities()) {
    if (elem->GetTag() == "Enemy") {
      auto enemy_scope = elem->Get<ScopeComponent>();
      auto enemy_position = elem->Get<PositionComponent>();
      auto enemy_attack = elem->Get<AttackComponent>();
      if (enemy_scope->IsNext()) {
        enemy_position->x += 0.02;
      }
      if (enemy_scope->IsBack()) {
        enemy_position->x -= 0.02;
      }
    }
  }
}

void MovementSystem::Update() {
  enemiesUpdate();
  playerUpdate();
}
