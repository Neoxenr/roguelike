#include "levelgenerator.h"

LevelGenerator::LevelGenerator() {
  std::srand(static_cast<unsigned int>(std::time(nullptr)));
}

void LevelGenerator::generateLevel(const std::string level_name) {
  auto random_value = std::rand() % 10;

  for (auto i = random_value + 1; i >= 0; i--) {
    data[std::make_pair(level_name, std::make_pair(std::rand() % window_width, std::rand() % (window_height - 1)))] =
        coin_texture;
  }

  random_value = (std::rand() % 80) + 1;

  for (auto i = random_value; i >= 0; i--) {
    auto temp_random = (std::rand() % 20) + 1;
    auto point = std::make_pair(std::rand() % window_width, std::rand() % (window_height - 1));
    for (auto j = 0; j < temp_random; j++) {
      if (std::rand() % 2) {
        data[std::make_pair(level_name, std::make_pair(point.first + j, point.second))] = wall_texture;
      } else {
        if (point.second + j < window_height) {
          data[std::make_pair(level_name, std::make_pair(point.first, point.second + j))] = wall_texture;
        }
      }
    }
  }

  random_value = (std::rand() % 3) + 1;

  for (auto i = random_value; i >= 0; i--) {
    data[std::make_pair(level_name, std::make_pair(std::rand() % window_width, std::rand() % (window_height - 1)))] =
        enemy_texture;
  }

  data[std::make_pair(level_name, std::make_pair(std::rand() % window_width, std::rand() % (window_height - 1)))] =
      door_texture;
}

const std::map<std::pair<std::string, std::pair<int, int>>, char> &LevelGenerator::getData() {
  return data;
}
