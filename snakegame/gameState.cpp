#include <iostream>
#include <string>
#include "gridStuff.h"
#include "food.h"
#include "grid.h"
#include "snake.h"
#include "raylib.h"
#include "gameState.h"

using namespace std;


Game::Game() {
    foodEaten = 0;
    steps = 0;
    status = "RUNNING";
}


int Game::getWidth() const {
    return board.getWidth() + 200;
}


int Game::getHeight() const {
    return board.getHeight();
}


int Game::getFoodEaten() const {
    return foodEaten;
}


int Game::getSteps() const {
    return steps;
}


string Game::getStatus() const {
    return status;
}


void Game::reset() {
    snake = Snake();
    food = Food();
    foodEaten = 0;
    steps = 0;
    status = "RUNNING";
}


int Game::handleInput() {
    if (IsKeyPressed(KEY_R)) {
        reset();
        return 0;
    }

    if (status != "RUNNING") {
        return -1;
    }

    int result = 0;

    if (IsKeyPressed(KEY_UP)) {
        result = snake.move(-1, 0, board);
    } else if (IsKeyPressed(KEY_DOWN)) {
        result = snake.move(1, 0, board);
    } else if (IsKeyPressed(KEY_LEFT)) {
        result = snake.move(0, -1, board);
    } else if (IsKeyPressed(KEY_RIGHT)) {
        result = snake.move(0, 1, board);
    }

    if (result == 1) {
        steps++;
    } else if (result == -1) {
        status = "DEAD";
    }

    return result;
}


void Game::eatFood() {
    food.eliminate();
    foodEaten++;
    snake.eat();
}


void Game::update() {
    if (status != "RUNNING") {
        return;
    }
    if (snake.getIsAlive() && !food.getIsEaten() &&
    snake.getRow() == food.getRow() && snake.getCol() == food.getCol()) {
    eatFood();

        if (foodEaten >= 100) {
            status = "WON";
        } else {
            food.spawn(snake.getRow(), snake.getCol(),
                       snake.getBodyRow(), snake.getBodyCol(),
                       snake.getBodyLength(), board);
        }
    }

    if (steps >= 5000 && status == "RUNNING") {
        status = "TIMEOUT";
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

    int x = board.getWidth();
    DrawRectangle(x, 0, 200, board.getHeight(), LIGHTGRAY);
    DrawText("SNAKELAB", x + 15, 25, 25, BLACK);
    DrawText(("Steps: " + to_string(steps)).c_str(), x + 15, 95, 20, BLACK);
    DrawText(("Food: " + to_string(foodEaten)).c_str(), x + 15, 135, 20, BLACK);
    DrawText(("Length: " + to_string(snake.getBodyLength() + 1)).c_str(), x + 15, 175, 20, BLACK);
    DrawText("Status:", x + 15, 235, 20, BLACK);
    DrawText(status.c_str(), x + 15, 265, 20, DARKGRAY);
    DrawText("Goal: 100 food", x + 15, 345, 17, BLACK);
    DrawText("Max: 5000 steps", x + 15, 375, 17, BLACK);
    DrawText("Arrow keys: Move", x + 15, 475, 16, BLACK);
    DrawText("R: Restart", x + 15, 505, 16, BLACK);

    if (status != "RUNNING") {
        DrawRectangle(105, 220, 390, 165, RAYWHITE);

        if (status == "WON") {
            DrawText("YOU WIN!", 175, 250, 40, DARKGREEN);
        } else if (status == "DEAD") {
            DrawText("GAME OVER", 165, 250, 40, BLACK);
        } else if (status == "TIMEOUT") {
            DrawText("TIME LIMIT", 165, 250, 40, BLACK);
        }

        DrawText(("Food eaten: " + to_string(foodEaten)).c_str(), 180, 310, 24, BLACK);
        DrawText("Press R to restart", 180, 350, 20, DARKGRAY);
    }

    EndDrawing();
}
