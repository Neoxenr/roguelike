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
          //  если игрок в стене заспавнился
        }
        if (elem->GetTag() == "Enemy") {
          check_object->is_enemy = true;
        }
        if (elem->GetTag() == "NextDoor") {
          check_object->is_next_door = true;
          level->setCompleted(1);
        }
        if (elem->GetTag() == "BackDoor") {
          check_object->is_back_door = true;
        }
      }
      if ((static_cast<int>(elem_position->getX()) - static_cast<int>(position->getX()) == 1) &&
          (static_cast<int>(elem_position->getY()) == static_cast<int>(position->getY())) && elem->GetTag() == "Wall") {
        check_object->right_object = true;
      }
      if ((static_cast<int>(position->getX()) - static_cast<int>(elem_position->getX()) == 1) &&
          (static_cast<int>(elem_position->getY()) == static_cast<int>(position->getY())) && elem->GetTag() == "Wall") {
        check_object->left_object = true;
      }
      if ((static_cast<int>(elem_position->getY()) - static_cast<int>(position->getY()) == 1) &&
          (static_cast<int>(elem_position->getX()) == static_cast<int>(position->getX())) && elem->GetTag() == "Wall") {
        check_object->down_object = true;
      }
      if ((static_cast<int>(position->getY()) - static_cast<int>(elem_position->getY()) == 1) &&
          (static_cast<int>(elem_position->getX()) == static_cast<int>(position->getX())) && elem->GetTag() == "Wall") {
        check_object->up_object = true;
      }
    }
  }
}
