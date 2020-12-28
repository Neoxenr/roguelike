#include "../include/systems/collisionsystem.h"

#include "../include/components/levelsinformationcomponent.h"

void CollisionSystem::backdoorUpdate() {
  if (GetEntityManager()->FindFirstByTag("BackDoor")) {
    auto backdoor = GetEntityManager()->FindFirstByTag("BackDoor");
    auto backdoor_position = backdoor->Get<PositionComponent>();

    for (const auto &id : GetEntityManager()->getAllIdByTag("Wall")) {
      auto temp = GetEntityManager()->FindById(id);
      auto temp_position = temp->Get<PositionComponent>();
      if (static_cast<int>(backdoor_position->getX()) == static_cast<int>(temp_position->getX()) &&
          static_cast<int>(backdoor_position->getY()) == static_cast<int>(temp_position->getY())) {
        GetEntityManager()->DeleteEntity(id);
        break;
      }
    }
  }
}

void CollisionSystem::playerUpdate() {
  auto player = GetEntityManager()->FindFirstByTag("Player");
  auto position = player->Get<PositionComponent>();
  auto check_object = player->Get<CollisionComponent>();
  auto level = player->Get<LevelsInformationComponent>();

  check_object->up_object = false;
  check_object->down_object = false;
  check_object->left_object = false;
  check_object->right_object = false;
  check_object->is_enemy = false;
  check_object->is_coin = false;

  for (const auto &elem : GetEntityManager()->getEntities()) {
    if (elem->GetTag() != "Player") {
      auto elem_position = elem->Get<PositionComponent>();

      if (static_cast<int>(elem_position->getX()) == static_cast<int>(position->getX()) &&
          static_cast<int>(elem_position->getY()) == static_cast<int>(position->getY())) {
        if (elem->GetTag() == "Coin") {
          GetEntityManager()->DeleteEntity(elem->GetId());
          check_object->is_coin = true;
          break;
        }
        if (elem->GetTag() == "Wall") {
          GetEntityManager()->DeleteEntity(elem->GetId());
          break;
        }
        if (elem->GetTag() == "NextDoor") {
          check_object->is_next_door = true;
          level->setCompleted(true);
        }
        if (elem->GetTag() == "BackDoor") {
          check_object->is_back_door = true;
        }
      }
      if ((static_cast<int>(elem_position->getX()) - static_cast<int>(position->getX()) == 1) &&
          (static_cast<int>(elem_position->getY()) == static_cast<int>(position->getY()))) {
        if (elem->GetTag() == "Wall") {
          check_object->right_object = true;
        }
        if (elem->GetTag() == "Enemy") {
          check_object->is_enemy = true;
        }
      }
      if ((static_cast<int>(position->getX()) - static_cast<int>(elem_position->getX()) == 1) &&
          (static_cast<int>(elem_position->getY()) == static_cast<int>(position->getY()))) {
        if (elem->GetTag() == "Wall") {
          check_object->left_object = true;
        }
        if (elem->GetTag() == "Enemy") {
          check_object->is_enemy = true;
        }
      }
      if ((static_cast<int>(elem_position->getY()) - static_cast<int>(position->getY()) == 1) &&
          (static_cast<int>(elem_position->getX()) == static_cast<int>(position->getX()))) {
        if (elem->GetTag() == "Wall") {
          check_object->down_object = true;
        }
        if (elem->GetTag() == "Enemy") {
          check_object->is_enemy = true;
        }
      }
      if ((static_cast<int>(position->getY()) - static_cast<int>(elem_position->getY()) == 1) &&
          (static_cast<int>(elem_position->getX()) == static_cast<int>(position->getX()))) {
        if (elem->GetTag() == "Wall") {
          check_object->up_object = true;
        }
        if (elem->GetTag() == "Enemy") {
          check_object->is_enemy = true;
        }
      }
    }
  }
}

void CollisionSystem::enemiesUpdate() {
  for (auto &all_id : GetEntityManager()->getAllIdByTag("Enemy")) {
    const auto &enemy = GetEntityManager()->FindById(all_id);
    const auto &enemy_position = enemy->Get<PositionComponent>();
    auto enemy_scope = enemy->Get<ScopeComponent>();
    auto enemy_attack = enemy->Get<AttackComponent>();
    auto enemy_collision = enemy->Get<CollisionComponent>();

    enemy_collision->right_object = false;
    enemy_collision->left_object = false;
    enemy_collision->up_object = false;
    enemy_collision->down_object = false;
    enemy_collision->is_player = false;

    for (const auto &obstacles : GetEntityManager()->getEntities()) {
      const auto &obstacle_position = obstacles->Get<PositionComponent>();
      if (obstacles->GetTag() != "Enemy" && obstacles->GetTag() != "Point") {
        if ((static_cast<int>(obstacle_position->getX()) - static_cast<int>(enemy_position->getX()) == 1) &&
            (static_cast<int>(enemy_position->getY()) == static_cast<int>(obstacle_position->getY()))) {
          if (obstacles->GetTag() == "Player") {
            enemy_collision->is_player = true;
          } else {
            enemy_collision->right_object = true;
          }
        }
        if ((static_cast<int>(enemy_position->getX()) - static_cast<int>(obstacle_position->getX()) == 1) &&
            (static_cast<int>(obstacle_position->getY()) == static_cast<int>(enemy_position->getY()))) {
          if (obstacles->GetTag() == "Player") {
            enemy_collision->is_player = true;
          } else {
            enemy_collision->left_object = true;
          }
        }
        if ((static_cast<int>(obstacle_position->getY()) - static_cast<int>(enemy_position->getY()) == 1) &&
            (static_cast<int>(obstacle_position->getX()) == static_cast<int>(enemy_position->getX()))) {
          if (obstacles->GetTag() == "Player") {
            enemy_collision->is_player = true;
          } else {
            enemy_collision->down_object = true;
          }
        }
        if ((static_cast<int>(enemy_position->getY()) - static_cast<int>(obstacle_position->getY()) == 1) &&
            (static_cast<int>(obstacle_position->getX()) == static_cast<int>(enemy_position->getX()))) {
          if (obstacles->GetTag() == "Player") {
            enemy_collision->is_player = true;
          } else {
            enemy_collision->up_object = true;
          }
        }
      }
    }

    if (static_cast<int>(enemy_position->getX()) == static_cast<int>(enemy_scope->getXMax()) ||
        static_cast<int>(enemy_position->getX()) == window_width || enemy_collision->right_object) {
      enemy_scope->setNext(false);
      enemy_scope->setBack(true);
      enemy_attack->setAttack(false);
    }

    if (static_cast<int>(enemy_position->getX()) == static_cast<int>(enemy_scope->getXMin()) ||
        static_cast<int>(enemy_position->getX()) == 0 || enemy_collision->left_object) {
      enemy_scope->setNext(true);
      enemy_scope->setBack(false);
      enemy_attack->setAttack(false);
    }
  }
}

void CollisionSystem::Update() {
  enemiesUpdate();
  playerUpdate();
  backdoorUpdate();
}
