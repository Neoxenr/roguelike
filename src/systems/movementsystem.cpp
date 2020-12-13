#include "../include/systems/movementsystem.h"

#include "../include/components/levelsinformationcomponent.h"

void MovementSystem::Update() {
  auto player = GetEntityManager()->FindFirstByTag("Player");
  auto controls = player->Get<ControlsComponent>();
  auto collision = player->Get<CollisionComponent>();
  auto position = player->Get<PositionComponent>();
  auto level = player->Get<LevelsInformationComponent>();

  if (controls->IsUp() && !collision->IsUpObject() && position->y > 0 && !level->IsCompleted()) {
    position->y -= 1;
  }

  if (controls->IsDown() && !collision->IsDownObject() && position->y < window_height && !level->IsCompleted()) {
    position->y += 1;
  }

  if (controls->IsRight() && !collision->IsRightObject() && position->x < window_widht && !level->IsCompleted()) {
    position->x += 1;
  }

  if (controls->IsLeft() && !collision->IsLeftObject() && position->x > 0 && !level->IsCompleted()) {
    position->x -= 1;
  }
}
