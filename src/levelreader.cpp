#include "levelreader.h"

#include "../include/config.h"

LevelReader::LevelReader() {}

void LevelReader::readLevel(const std::string name) {
  file.open("levels/" + name + ".txt");

  if (file.is_open()) {
    while (!file.eof()) {
      std::string str;
      getline(file, str);
      if (str.substr(6).c_str()[0] == coin_texture) {
        data[std::make_pair(name, std::make_pair(std::stoi(str.substr(0, 2)), std::stoi(str.substr(3, 2))))] =
            coin_texture;
      }
      if (str.substr(6).c_str()[0] == wall_texture) {
        data[std::make_pair(name, std::make_pair(std::stoi(str.substr(0, 2)), std::stoi(str.substr(3, 2))))] =
            wall_texture;
      }
      if (str.substr(6).c_str()[0] == door_texture) {
        data[std::make_pair(name, std::make_pair(std::stoi(str.substr(0, 2)), std::stoi(str.substr(3, 2))))] =
            door_texture;
      }
      if (str.substr(6).c_str()[0] == enemy_texture) {
        data[std::make_pair(name, std::make_pair(std::stoi(str.substr(0, 2)), std::stoi(str.substr(3, 2))))] =
            enemy_texture;
      }
    }
    file.close();
  }
}

const std::map<std::pair<std::string, std::pair<int, int>>, char>& LevelReader ::getData() {
  return data;
}
