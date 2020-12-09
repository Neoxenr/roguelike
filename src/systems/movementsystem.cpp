#include "../include/systems/movementsystem.h"

#include "../include/components/levelinformationcomponent.h"

void MovementSystem::Update() {
  auto player = GetEntityManager()->FindFirstByTag("Player");
  auto controls = player->Get<ControlsComponent>();
  auto collision = player->Get<CollisionComponent>();
  auto position = player->Get<PositionComponent>();
  auto level = player->Get<LevelInformationComponent>();

  if (controls->IsUp() && !collision->IsUpObject() &&
      position->y > 0 && !level->IsCompleted()) {
    position->y -= 1;
  }

  if (controls->IsDown() && !collision->IsDownObject() &&
      position->y < 23 && !level->IsCompleted()) {
    position->y += 1;
  }

  if (controls->IsRight() && !collision->IsRightObject() &&
      position->x < 79 && !level->IsCompleted()) {
    position->x += 1;
  }

  if (controls->IsLeft() && !collision->IsLeftObject() &&
      position->x > 0 && !level->IsCompleted()) {
    position->x -= 1;
  }
}
