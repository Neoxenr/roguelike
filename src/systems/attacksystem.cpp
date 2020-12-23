#include "../include/systems/attacksystem.h"

void AttackSystem::Update() {
  auto player = GetEntityManager()->FindFirstByTag("Player");
  auto collision = player->Get<CollisionComponent>();
  auto player_health = player->Get<HealthComponent>();

  if (collision->IsEnemy()) {
    player_health->health -= 0.25;
  }
}
