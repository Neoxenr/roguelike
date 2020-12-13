#include "levelreader.h"

#include "../include/config.h"

void LevelReader::readLevel(const std::string name) {
  file.open("levels/" + name + ".txt");
  while (!file.eof()) {
    std::string str;
    getline(file, str);
    if (str.substr(6).c_str()[0] == coin_texture) {
      data[std::make_pair(name, std::make_pair(std::stoi(str.substr(0, 2)), std::stoi(str.substr(3, 2))))] = '$';
    }
    if (str.substr(6).c_str()[0] == wall_texture) {
      data[std::make_pair(name, std::make_pair(std::stoi(str.substr(0, 2)), std::stoi(str.substr(3, 2))))] = '#';
    }
    if (str.substr(6).c_str()[0] == door_texture) {
      data[std::make_pair(name, std::make_pair(std::stoi(str.substr(0, 2)), std::stoi(str.substr(3, 2))))] = '>';
    }
  }
  file.close();
}

const std::map<std::pair<std::string, std::pair<int, int>>, char>& LevelReader ::getData() {
  return data;
}
