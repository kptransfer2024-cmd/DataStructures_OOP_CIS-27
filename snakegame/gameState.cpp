#include <iostream>
#include <string>
#include "gridStuff.h"
#include "food.h"
#include "grid.h"
#include "snake.h"
#include "raylib.h"
#include "gameState.h"

using namespace std;


Game::Game(){
    foodEaten = 0;
}


int Game::getWidth() const {
    return board.getWidth();
}


int Game::getHeight() const {
    return board.getHeight();
}


int Game::getFoodEaten() const {
    return foodEaten;
}

int Game::handleInput() {
    if (!snake.getIsAlive()) {
        return -1;
    }

    if (IsKeyPressed(KEY_UP)) {
        return snake.move(-1, 0, board);
    } else if (IsKeyPressed(KEY_DOWN)) {
        return snake.move(1, 0, board);
    } else if (IsKeyPressed(KEY_LEFT)) {
        return snake.move(0, -1, board);
    } else if (IsKeyPressed(KEY_RIGHT)) {
        return snake.move(0, 1, board);
    }
    return 0;
}


void Game::eatFood() {
    food.eliminate();
    foodEaten ++;
    snake.eat();
}


void Game::update() {
    if (snake.getIsAlive() && !food.getIsEaten() && snake.getRow() == food.getRow() && snake.getCol() == food.getCol()) {
            eatFood();
    }

    if (snake.getIsAlive() && food.getIsEaten()) {
        food.spawn(snake.getRow(), snake.getCol(), snake.getBodyRow(), snake.getBodyCol(), snake.getBodyLength(), board);
    }
}




void Game::depict() {
    BeginDrawing();

    ClearBackground(RAYWHITE);
    board.draw();
    snake.drawHead();
    snake.drawBody();

    if (!food.getIsEaten()) {
        food.draw();
    }


    if (!snake.getIsAlive()) {
        DrawText("GAME OVER", 180, 270, 40, BLACK);
        DrawText(("You ate " + std::to_string(getFoodEaten()) + " food!").c_str(), 160, 320, 30, BLACK);
    }
    EndDrawing();
}