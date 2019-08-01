#include <iostream>
#include <SFML/Graphics.hpp>
#include "Snake.hpp"
#include "Food.hpp"
using namespace sf;

int main()
{
  //Intilized the game
  int windowWidth = 630;
  int windowLen = 450;
  RenderWindow window(VideoMode(windowWidth, windowLen), "Snake Game");
  window.setFramerateLimit(10);
  Texture t;
  Sprite s(t);
  t.loadFromFile("images/tiles.png");
  s.setTextureRect(IntRect(0, 0, 18, 18));
  Snake snake(s);
  Food food(s);
  bool checkFood = true;

  while (window.isOpen())
  {
    //Handle Event
    Event e;
    while (window.pollEvent(e))
    {
      if (e.type == Event::Closed)
        window.close();
      if (e.type == Event::KeyPressed)
      {
        snake.handleEvent(e);
      }
    }

    //Update the game
    checkFood = snake.CheckFoodCollision(food.GetShape());
    snake.ChangeArray();
    snake.CheckFoodCollision(food.GetShape());
    if (checkFood)
    {
      food.UpdatePosition();
      checkFood = false;
    }

    //Draw the game
    window.clear(Color::White);
    snake.Draw(window);
    food.Draw(window);
    window.display();
  }
}