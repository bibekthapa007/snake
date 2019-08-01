#include "BaseObject.hpp"

using namespace sf;

BaseObject::BaseObject()
{
  Texture t;
  t.loadFromFile("images/tiles.png");
  Sprite s(t);
  s.setTextureRect(IntRect(0, 0, 18, 18));
  this->s = s;
}
