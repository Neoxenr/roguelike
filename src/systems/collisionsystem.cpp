#include "../include/systems/collisionsystem.h"

#include "../include/components/levelinformationcomponent.h"

void CollisionSystem::Update() {
  auto player = GetEntityManager()->FindFirstByTag("Player");
  auto position = player->Get<PositionComponent>();
  auto check_object = player->Get<CollisionComponent>();
  auto level = player->Get<LevelInformationComponent>();

  check_object->up_object = false;
  check_object->down_object = false;
  check_object->left_object = false;
  check_object->right_object = false;
  check_object->is_coin = false;

  for (const auto &elem : GetEntityManager()->getEntities()) {
    if (elem->GetTag() != "Player") {
      auto elem_position = elem->Get<PositionComponent>();
      if ((elem_position->getX() - position->getX() == 1 || elem_position->getX() - position->getX() == 0) &&
          elem_position->getY() == position->getY()) {
        if (elem->GetTag() == "Coin" && elem_position->getX() - position->getX() == 0) {
          GetEntityManager()->DeleteEntity(elem->GetId());
          check_object->is_coin = true;
        } else if (elem->GetTag() == "Wall" && elem_position->getX() - position->getX() == 1) {
          check_object->right_object = true;
        } else if (elem->GetTag() == "Door" && position->getX() - elem_position->getX() == 0) {
          GetEntityManager()->DeleteEntity(elem->GetId());
          level->setCompleted(1);
        }
        break;
      }

      if ((position->getX() - elem_position->getX() == 1 || position->getX() - elem_position->getX() == 0) &&
          elem_position->getY() == position->getY()) {
        if (elem->GetTag() == "Coin" && position->getX() - elem_position->getX() == 0) {
          GetEntityManager()->DeleteEntity(elem->GetId());
          check_object->is_coin = true;
        } else if (elem->GetTag() == "Wall" && position->getX() - elem_position->getX() == 1) {
          check_object->left_object = true;
        } else if (elem->GetTag() == "Door" && position->getX() - elem_position->getX() == 0) {
          GetEntityManager()->DeleteEntity(elem->GetId());
          level->setCompleted(1);
        }
        break;
      }

      if ((elem_position->getY() - position->getY() == 1 || elem_position->getY() - position->getY() == 0) &&
          elem_position->getX() == position->getX()) {
        if (elem->GetTag() == "Coin" && elem_position->getY() - position->getY() == 0) {
          GetEntityManager()->DeleteEntity(elem->GetId());
          check_object->is_coin = true;
        } else if (elem->GetTag() == "Wall" && elem_position->getY() - position->getY() == 1) {
          check_object->down_object = true;
        } else if (elem->GetTag() == "Door" && position->getY() - elem_position->getY() == 0) {
          GetEntityManager()->DeleteEntity(elem->GetId());
          level->setCompleted(1);
        }
        break;
      }

      if ((position->getY() - elem_position->getY() == 1 || position->getY() - elem_position->getY() == 0) &&
          elem_position->getX() == position->getX()) {
        if (elem->GetTag() == "Coin" && position->getY() - elem_position->getY() == 0) {
          GetEntityManager()->DeleteEntity(elem->GetId());
          check_object->is_coin = true;
        } else if (elem->GetTag() == "Wall" && position->getY() - elem_position->getY() == 1) {
          check_object->up_object = true;
        } else if (elem->GetTag() == "Door" && position->getY() - elem_position->getY() == 0) {
          GetEntityManager()->DeleteEntity(elem->GetId());
          level->setCompleted(1);
        }
        break;
      }
    }
  }
}
