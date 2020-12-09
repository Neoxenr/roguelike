#pragma once

#include <string>

#include "lib/i_component.h"

class TextureComponent : public IComponent {
 private:
  char texture;
  std::string color;

 public:
  TextureComponent(const char _texture, const std::string _color) : texture(_texture), color(_color) {}
  explicit TextureComponent(const char _texture) : texture(_texture), color("white") {}
  char getTexture() const;
  std::string getColor() const;
};
