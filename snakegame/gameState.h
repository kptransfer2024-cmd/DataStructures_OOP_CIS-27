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

    int mode;
    double lastAutoMove;
    int simSteps[300];
    int simFood[300];
    string simStatus[300];


    bool isSafeCell(int row, int col);
    void manualDirection(int& rowChange, int& colChange);
    bool randomDirection(int& rowChange, int& colChange);
    bool greedyDirection(int& rowChange, int& colChange);
    bool bfsDirection(int& rowChange, int& colChange);
    void runSimulation();
    int moveSnake(int rowChange, int colChange);

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
