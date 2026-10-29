#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <string>
#include "grid.h"
#include "snake.h"
#include "food.h"

using namespace std;

class Game {
private:
    Grid board;
    Snake snake;
    Food food;
    int foodEaten;
    int steps;
    string status;

public:
    Game();

    int getWidth() const;
    int getHeight() const;
    int getFoodEaten() const;
    int getSteps() const;
    string getStatus() const;

    int handleInput();
    void eatFood();
    void update();
    void reset();
    void depict();
};

#endif
