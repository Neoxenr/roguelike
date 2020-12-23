#include "levelgenerator.h"

void LevelGenerator::generateLevel(const std::string level_name) {
  auto random_value = std::rand() % 10;

  for (auto i = random_value + 1; i >= 0; i--) {
    data[std::make_pair(level_name, std::make_pair(std::rand() % window_width, std::rand() % window_height))] =
        coin_texture;
  }

  random_value = std::rand() % 10;

  for (auto i = random_value + 1; i >= 0; i--) {
    auto temp_random = std::rand() % 5;
    auto point = std::make_pair(std::rand() % window_width, std::rand() % window_height);
    for (auto j = 0; j < temp_random + 1; j++) {
      if (std::rand() % 2) {
        data[std::make_pair(level_name, std::make_pair(point.first + j, point.second))] = wall_texture;
      } else {
        data[std::make_pair(level_name, std::make_pair(point.first, point.second + j))] = wall_texture;
      }
    }
  }

  random_value = std::rand() % 3;

  for (auto i = random_value + 1; i >= 0; i--) {
    data[std::make_pair(level_name, std::make_pair(std::rand() % window_width, std::rand() % window_height))] =
        enemy_texture;
  }

  data[std::make_pair(level_name, std::make_pair(std::rand() % window_width, std::rand() % window_height))] =
      door_texture;
}

const std::map<std::pair<std::string, std::pair<int, int>>, char> &LevelGenerator::getData() {
  return data;
}
