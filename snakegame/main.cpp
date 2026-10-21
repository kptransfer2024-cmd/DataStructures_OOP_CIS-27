#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>

#include "gameState.h"
#include "gridStuff.h"
#include "grid.h"
#include "snake.h"
#include "food.h"
#include "raylib.h"
using namespace std;



int main() {

    srand(static_cast<unsigned int>(time(0)));

    Game game;

    InitWindow(game.getWidth(), game.getHeight(), "SnakeGame");

    SetTargetFPS(60);


    while (!WindowShouldClose()) {
        game.handleInput();
        game.update();

        game.depict();
    }

    CloseWindow();
    return 0;

}