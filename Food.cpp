#include "Food.hpp"
#include "point.hpp"

using namespace sf;

point generateFood()
{
  point a;
  a.x = (rand() % 35);
  a.y = (rand() % 25);
  return a;
}

Food::Food(Sprite sprite)
{
  s = sprite;
  fpos = generateFood();
}

void Food::Draw(RenderWindow &window)
{
  s.setPosition(fpos.x * 18, fpos.y * 18);
  window.draw(s);
}

void Food::UpdatePosition()
{
  fpos = generateFood();
}

point Food::GetShape()
{
  return fpos;
}