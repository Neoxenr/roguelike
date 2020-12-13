#pragma once

#include <string>

class IReader {
 public:
  virtual void readLevel(std::string level_name) = 0;
  virtual ~IReader() = default;
};
