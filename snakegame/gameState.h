#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>

#include "gridStuff.h"
#include "grid.h"
#include "snake.h"
#include "food.h"
#include "raylib.h"

class Game  {
private:
    Grid board;
    Snake snake;
    Food food;
    int foodEaten;

public:
    Game();

    int getWidth() const;
    int getHeight() const;
    int getFoodEaten() const;
    int handleInput();
    void eatFood();
    void update();
    void depict();



};


#endif