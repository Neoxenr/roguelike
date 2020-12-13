#include "levelgenerator.h"

void LevelGenerator::generateLevel(const std::string level_name) {
  for (auto i = 0; i < (std::rand() % 10) + 1; i++) {
    data[std::make_pair(level_name, std::make_pair(std::rand() % window_widht, std::rand() % window_height))] =
        coin_texture;
  }

  for (auto i = 0; i < (std::rand() % 10) + 1; i++) {
    data[std::make_pair(level_name, std::make_pair(std::rand() % window_widht, std::rand() % window_height))] =
        wall_texture;
  }

  data[std::make_pair(level_name, std::make_pair(std::rand() % window_widht, std::rand() % window_height))] =
      door_texture;
}

const std::map<std::pair<std::string, std::pair<int, int>>, char> &LevelGenerator::getData() {
  return data;
}
