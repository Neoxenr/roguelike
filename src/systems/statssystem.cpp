#include "../include/systems/statssystem.h"

#include "../include/components/levelinformationcomponent.h"

void StatsSystem::Update() {
  auto player = GetEntityManager()->FindFirstByTag("Player");
  auto stats = player->Get<StatsComponent>();
  auto position = player->Get<PositionComponent>();
  auto controls = player->Get<ControlsComponent>();
  auto collision = player->Get<CollisionComponent>();
  auto level = player->Get<LevelInformationComponent>();

  if (level->IsCompleted() && controls->IsEnter()) {
    stats->steps_count = 0;
    stats->coins_count = 0;
  }

  if (collision->IsCoin()) {
    ++stats->coins_count;
  }

  if (controls->IsUp() && !collision->IsUpObject() && position->getY() > 0 && !level->IsCompleted()) {
    ++stats->steps_count;
  }

  if (controls->IsDown() && !collision->IsDownObject() && position->getY() < 23 && !level->IsCompleted()) {
    ++stats->steps_count;
  }

  if (controls->IsRight() && !collision->IsRightObject() && position->getX() < 79 && !level->IsCompleted()) {
    ++stats->steps_count;
  }

  if (controls->IsLeft() && !collision->IsLeftObject() && position->getX() > 0 && !level->IsCompleted()) {
    ++stats->steps_count;
  }
}
