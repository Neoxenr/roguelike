#include "../include/systems/collisionsystem.h"

#include "../include/components/levelsinformationcomponent.h"

void CollisionSystem::Update() {
  auto player = GetEntityManager()->FindFirstByTag("Player");
  auto position = player->Get<PositionComponent>();
  auto check_object = player->Get<CollisionComponent>();
  auto level = player->Get<LevelsInformationComponent>();

  check_object->up_object = false;
  check_object->down_object = false;
  check_object->left_object = false;
  check_object->right_object = false;
  check_object->is_coin = false;

  for (const auto &elem : GetEntityManager()->getEntities()) {
    if (elem->GetTag() != "Player") {
      auto elem_position = elem->Get<PositionComponent>();

      if (elem_position->getX() == position->getX() && elem_position->getY() == position->getY()) {
        if (elem->GetTag() == "Coin") {
          GetEntityManager()->DeleteEntity(elem->GetId());
          check_object->is_coin = true;
          break;
        }
        if (elem->GetTag() == "NextDoor") {
          check_object->is_next_door = true;
          level->setCompleted(1);
        }
        if (elem->GetTag() == "BackDoor") {
          check_object->is_back_door = true;
        }
      }
      if ((elem_position->getX() - position->getX() == 1) && (elem_position->getY() == position->getY()) &&
          elem->GetTag() == "Wall") {
        check_object->right_object = true;
      }
      if ((position->getX() - elem_position->getX() == 1) && (elem_position->getY() == position->getY()) &&
          elem->GetTag() == "Wall") {
        check_object->left_object = true;
      }
      if ((elem_position->getY() - position->getY() == 1) && (elem_position->getX() == position->getX()) &&
          elem->GetTag() == "Wall") {
        check_object->down_object = true;
      }
      if ((position->getY() - elem_position->getY() == 1) && (elem_position->getX() == position->getX()) &&
          elem->GetTag() == "Wall") {
        check_object->up_object = true;
      }
    }
  }
}
