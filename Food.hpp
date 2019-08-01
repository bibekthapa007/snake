#pragma once
#include <SFML/Graphics.hpp>
#include "point.hpp"

using namespace sf;


class Food
{
public:
  Food(Sprite s);
  void Draw(RenderWindow &window);
  point GetShape();
  void UpdatePosition();
private:
  Sprite s;
  point fpos;
};

