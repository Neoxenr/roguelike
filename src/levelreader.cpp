#include "levelreader.h"

void LevelReader::readLevel(std::string level_name) {
  file.open("levels/" + level_name);
  if (file.is_open()) {
    while (!file.eof()) {
      std::string str;
      getline(file, str);
      if (str.substr(6) == "$") {
        coins->Create(std::stoi(str.substr(0, 2)), std::stoi(str.substr(3, 2)), '$');
      }
      if (str.substr(6) == "#") {
        walls->Create(std::stoi(str.substr(0, 2)), std::stoi(str.substr(3, 2)), '#');
      }
    }
  }
  file.close();
}
