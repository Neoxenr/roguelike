#include "../include/systems/movementsystem.h"

#include "../include/components/levelsinformationcomponent.h"

void MovementSystem::Update() {
  auto player = GetEntityManager()->FindFirstByTag("Player");
  auto controls = player->Get<ControlsComponent>();
  auto collision = player->Get<CollisionComponent>();
  auto position = player->Get<PositionComponent>();
  auto level = player->Get<LevelsInformationComponent>();

  for (auto& elem : GetEntityManager()->getEntities()) {
    if (elem->GetTag() == "Enemy") {
      auto enemy_scope = elem->Get<ScopeComponent>();
      auto enemy_position = elem->Get<PositionComponent>();
      if (enemy_scope->IsNext()) {
        if (static_cast<int>(enemy_position->x) == static_cast<int>(enemy_scope->getXMax()) ||
            static_cast<int>(enemy_position->x) == window_width) {
          enemy_scope->setNext(false);
          enemy_scope->setBack(true);
        }
        enemy_position->x += 0.05;
      }
      if (enemy_scope->IsBack()) {
        if (static_cast<int>(enemy_position->x) == static_cast<int>(enemy_scope->getXMin()) ||
            static_cast<int>(enemy_position->x) == 0) {
          enemy_scope->setNext(true);
          enemy_scope->setBack(false);
        }
        enemy_position->x -= 0.05;
      }
    }
  }

  if (controls->IsUp() && !collision->IsUpObject() && position->y > 0 && !level->IsCompleted()) {
    position->y -= 1;
  }

  if (controls->IsDown() && !collision->IsDownObject() && position->y < window_height && !level->IsCompleted()) {
    position->y += 1;
  }

  if (controls->IsRight() && !collision->IsRightObject() && position->x < window_width && !level->IsCompleted()) {
    position->x += 1;
  }

  if (controls->IsLeft() && !collision->IsLeftObject() && position->x > 0 && !level->IsCompleted()) {
    position->x -= 1;
  }
}
