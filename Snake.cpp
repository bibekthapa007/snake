#include "Snake.hpp"
#include "iostream"

Snake::Snake(Sprite sprite)
{
  s = sprite;
  dx = 0;
  dy = 1;
}

void Snake::Draw(RenderWindow &window)
{
  for (int i = 0; i < length; i++)
  {
    s.setPosition(snakePos[i].x * 18, snakePos[i].y * 18);
    window.draw(s);
  }
}

bool Snake::CheckFoodCollision(point food)
{
  if ((snakePos[0].x == food.x))
  {
    if ((snakePos[0].y == food.y))
    {
      snakePos[length].x = snakePos[length - 1].x;
      snakePos[length].y = snakePos[length - 1].y;
      length++;
      return true;
    }
    return false;
  }
  return false;
}

void Snake::ChangeArray()
{

  for (int i = length - 1; i > 0; i--)
  {
    snakePos[i].x = snakePos[i - 1].x;
    snakePos[i].y = snakePos[i - 1].y;
  }
  snakePos[0].x = snakePos[0].x + dx;
  snakePos[0].y = snakePos[0].y + dy;
}

void Snake::handleEvent(Event e)
{

  if (e.key.code == Keyboard::Right)
  {
    if (dx == 0)
    {
      dx = 1;
      dy = 0;
    }
  }
  if (e.key.code == Keyboard::Left)
  {
    if (dx == 0)
    {
      dx = -1;
      dy = 0;
    }
  }
  if (e.key.code == Keyboard::Up)
  {
    if (dy == 0)
    {
      dy = -1;
      dx = 0;
    }
  }
  if (e.key.code == Keyboard::Down)
  {
    if (dy == 0)
    {
      dy = 1;
      dx = 0;
    }
  }
}