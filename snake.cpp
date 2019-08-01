#include <iostream>
#include <SFML/Graphics.hpp>
#include <time.h>
#include <string.h>
#include <algorithm>
using namespace sf;

struct point
{
  int x, y;
};

int length = 4;

point snake[40] = {
    1, 1, //first point
    2, 1,
    3, 1,
    4, 1};

void changeArray(point *value, int x, int y)
{
  for (int i = length - 1; i > 0; i--)
  {
    value[i].x = value[i - 1].x;
    value[i].y = value[i - 1].y;
  }
  value[0].x = x;
  value[0].y = y;
}

point generateFood()
{
  point a;
  a.x = (rand() % 35);
  a.y = (rand() % 25);
  return a;
}

bool checkFoodCollision(point *snake, point food)
{

  if ((snake[0].x == food.x))
  {
    if ((snake[0].y == food.y))
    {
      snake[length].x = snake[length - 1].x;
      snake[length].y = snake[length - 1].y;
      return true;
    }
    return false;
  }
  return false;
}

int main()
{
  int windowWidth = 630;
  int windowLen = 450;
  RenderWindow window(VideoMode(windowWidth, windowLen), "Snake Game");
  Texture t;
  Sprite s(t);
  t.loadFromFile("images/tiles.png");
  s.setTextureRect(IntRect(0, 0, 18, 18));

  int dx = 0;
  int dy = 1;

  float timer = 0, delay = 0.1;

  Clock clock;
  point fpos;
  fpos = generateFood();
  bool food = true;

  while (window.isOpen())
  {
    float time = clock.getElapsedTime().asSeconds();
    clock.restart();
    timer += time;

    Event e;
    while (window.pollEvent(e))
    {
      if (e.type == Event::Closed)
        window.close();
      if (e.type == Event::KeyPressed)
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
    }

    ///Ticker
    if (timer > delay)
    {
      food = checkFoodCollision(snake, fpos);
      changeArray(snake, snake[0].x + dx, snake[0].y + dy);

      if (food)
      {
        fpos = generateFood();
        food = false;
        length++;
      }

      timer = 0;
    }

    window.clear(Color::White);
    for (int i = 0; i < length; i++)
    {
      s.setPosition(snake[i].x * 18, snake[i].y * 18);
      window.draw(s);
    }
    s.setPosition(fpos.x * 18, fpos.y * 18);
    window.draw(s);
    window.display();
  }
}