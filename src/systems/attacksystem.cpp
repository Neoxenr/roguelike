#include "../include/systems/attacksystem.h"

void AttackSystem::Update() {
  auto player = GetEntityManager()->FindFirstByTag("Player");
  auto player_health = player->Get<HealthComponent>();
  auto player_collision = player->Get<CollisionComponent>();

  for (const auto &enemy_id : GetEntityManager()->getAllIdByTag("Enemy")) {
    auto enemy = GetEntityManager()->FindById(enemy_id);
    auto enemy_attack = enemy->Get<AttackComponent>();
    auto enemy_collision = enemy->Get<CollisionComponent>();
    if (!enemy_attack->IsAttack() && enemy_collision->IsPlayer()) {
      player_health->health -= 5;
      enemy_attack->setAttack(true);
    }
  }
}
