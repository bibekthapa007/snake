#pragma once
#include <SFML/Graphics.hpp>
#include "BaseObject.hpp"
#include "point.hpp"

using namespace sf;

class Snake 
{
public:
  Snake(Sprite s);
  void Draw(RenderWindow &window);
  bool CheckFoodCollision(point food);
  void ChangeArray();
  void handleEvent(Event e);

private:
  RenderWindow *window;
  point snakePos[40] = {
      1, 1, //first point
      2, 1,
      3, 1,
      4, 1};
  int length = 4;
  Sprite s;
  int dy, dx;
};
