#include <iostream>
#include <string>
#include <cstdlib>
#include "gridStuff.h"
#include "food.h"
#include "grid.h"
#include "snake.h"
#include "raylib.h"
#include "gameState.h"
#include <queue>
#include <utility>
using namespace std;

Game::Game() {
    foodEaten = 0;
    steps = 0;
    status = "RUNNING";
    mode = 0;
    lastAutoMove = 0;
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
    lastAutoMove = GetTime();
}


void Game::manualDirection(int& rowChange, int& colChange) {
    if (IsKeyPressed(KEY_UP)) {
        rowChange = -1;
    } else if (IsKeyPressed(KEY_DOWN)) {
        rowChange = 1;
    } else if (IsKeyPressed(KEY_LEFT)) {
        colChange = -1;
    } else if (IsKeyPressed(KEY_RIGHT)) {
        colChange = 1;
    }
}



bool Game::randomDirection(int& rowChange, int& colChange) {
    int rowDirections[4] = {-1, 1, 0, 0};
    int colDirections[4] = {0, 0, -1, 1};
    int validDirections[4];
    int validCount = 0;

    for (int i = 0; i < 4; i++) {
        int newRow = snake.getRow() + rowDirections[i];
        int newCol = snake.getCol() + colDirections[i];

        if (!board.isInside(newRow, newCol)) {
            continue;
        }

        bool blocked = false;
        for (int j = 0; j < snake.getBodyLength(); j++) {
            if (newRow == snake.getBodyRow()[j] &&
                newCol == snake.getBodyCol()[j]) {
                blocked = true;
                break;
            }
        }

        if (!blocked) {
            validDirections[validCount] = i;
            validCount++;
        }
    }

    if (validCount == 0) {
        return false;
    }

    int chosen = validDirections[rand() % validCount];
    rowChange = rowDirections[chosen];
    colChange = colDirections[chosen];
    return true;
}


bool Game::greedyDirection(int& rowChange, int& colChange) {
    int rowDirections[4] = {0, 0, -1, 1};
    int colDirections[4] = {-1, 1, 0, 0};
    int bestDistance = 1000000;
    bool found = false;

    for (int i = 0; i < 4; i++) {
        int newRow = snake.getRow() + rowDirections[i];
        int newCol = snake.getCol() + colDirections[i];

        if (!board.isInside(newRow, newCol)) {
            continue;
        }

        if (snake.getBodyLength() > 0 &&
            newRow == snake.getBodyRow()[0] &&
            newCol == snake.getBodyCol()[0]) {
            continue;
        }

        int distance = abs(food.getRow() - newRow) + abs(food.getCol() - newCol);

        if (distance < bestDistance) {
            bestDistance = distance;
            rowChange = rowDirections[i];
            colChange = colDirections[i];
            found = true;
        }
    }
    return found;
}


bool Game::bfsDirection(int& rowChange, int& colChange) {
    queue<pair<int, int>> q;

    bool visited[20][20] = {false};
    int parentRow[20][20];
    int parentCol[20][20];

    int startRow = snake.getRow();
    int startCol = snake.getCol();
    int foodRow = food.getRow();
    int foodCol = food.getCol();

    int rowDirections[4] = {-1, 1, 0, 0};
    int colDirections[4] = {0, 0, -1, 1};

    q.push({startRow, startCol});
    visited[startRow][startCol] = true;

    bool found = false;

    int bestRow = startRow;
    int bestCol = startCol;
    int bestDistance = abs(startRow - foodRow) + abs(startCol - foodCol);

    while (!q.empty()) {
        pair<int, int> current = q.front();
        q.pop();

        int row = current.first;
        int col = current.second;
        
        int distance = abs(row - foodRow) + abs(col - foodCol);

        if ((row != startRow || col != startCol) && ((bestRow == startRow && bestCol == startCol) || distance < bestDistance)) {
            bestDistance = distance;
            bestRow = row;
            bestCol = col;
        }

        if (row == foodRow && col == foodCol) {
            found = true;
            break;
        }

        for (int i = 0; i < 4; i++) {
            int newRow = row + rowDirections[i];
            int newCol = col + colDirections[i];

            if (!board.isInside(newRow, newCol)) {
                continue;
            }

            if (visited[newRow][newCol]) {
                continue;
            }

            bool blocked = false;

            for (int j = 0; j < snake.getBodyLength(); j++) {
                if (newRow == snake.getBodyRow()[j] &&
                    newCol == snake.getBodyCol()[j]) {
                    blocked = true;
                    break;
                }
            }

            if (blocked) {
                continue;
            }

            visited[newRow][newCol] = true;
            parentRow[newRow][newCol] = row;
            parentCol[newRow][newCol] = col;

            q.push({newRow, newCol});
        }
    }

    int nextRow;
    int nextCol;

    if (found) {
        nextRow = foodRow;
        nextCol = foodCol;
    } 
    else {
        nextRow = bestRow;
        nextCol = bestCol;
    }

    if (nextRow == startRow && nextCol == startCol) {
        return false;
    }

    while (parentRow[nextRow][nextCol] != startRow ||
           parentCol[nextRow][nextCol] != startCol) {

        int prevRow = parentRow[nextRow][nextCol];
        int prevCol = parentCol[nextRow][nextCol];

        nextRow = prevRow;
        nextCol = prevCol;
    }

    rowChange = nextRow - startRow;
    colChange = nextCol - startCol;

    return true;
}


int Game::moveSnake(int rowChange, int colChange) {
    if (rowChange == 0 && colChange == 0) {
        return 0;
    }

    int result = snake.move(rowChange, colChange, board);

    if (result == 1) {
        steps++;
    } else if (result == -1) {
        status = "DEAD";
    }

    return result;
}


int Game::handleInput() {
    if (IsKeyPressed(KEY_ONE)) {
        mode = 0;
        reset();
        return 0;
    } 
    else if (IsKeyPressed(KEY_TWO)) {
        mode = 1;
        reset();
        return 0;
    } 
    else if (IsKeyPressed(KEY_THREE)) {
        mode = 2;
        reset();
        return 0;
    } 
    else if (IsKeyPressed(KEY_FOUR)) {
        mode = 3;
        reset();
        return 0;
    }
    else if (IsKeyPressed(KEY_R)) {
        reset();
        return 0;
}

    if (status != "RUNNING") {
        return -1;
    }

    int rowChange = 0;
    int colChange = 0;
    bool found = true;

    if (mode == 0) {
        manualDirection(rowChange, colChange);
    } else {
        if (GetTime() - lastAutoMove < 0.015) {
            return 0;
        }
        lastAutoMove = GetTime();

        if (mode == 1) {
            found = randomDirection(rowChange, colChange);
        } 
        else if (mode == 2) {
            found = greedyDirection(rowChange, colChange);
        }
        else if (mode == 3) {
            found = bfsDirection(rowChange, colChange);
        }
    }

    if (!found) {
        status = "DEAD";
        return -1;
    }

    return moveSnake(rowChange, colChange);
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

    if (mode == 0) {
        DrawText("Mode: MANUAL", x + 15, 60, 18, BLACK);
    } else if (mode == 1) {
        DrawText("Mode: RANDOM", x + 15, 60, 18, BLACK);
    } else if (mode == 2) {
        DrawText("Mode: GREEDY", x + 15, 60, 18, BLACK);
    } else if (mode == 3) {
        DrawText("Mode: BFS", x + 15, 60, 18, BLACK);
    }

    DrawText(("Steps: " + to_string(steps)).c_str(), x + 15, 105, 20, BLACK);
    DrawText(("Food: " + to_string(foodEaten)).c_str(), x + 15, 145, 20, BLACK);
    DrawText(("Length: " + to_string(snake.getBodyLength() + 1)).c_str(), x + 15, 185, 20, BLACK);
    DrawText("Status:", x + 15, 245, 20, BLACK);
    DrawText(status.c_str(), x + 15, 275, 20, DARKGRAY);
    DrawText("Goal: 100 food", x + 15, 345, 17, BLACK);
    DrawText("Max: 5000 steps", x + 15, 375, 17, BLACK);
    DrawText("1: Manual", x + 15, 425, 17, BLACK);
    DrawText("2: Random", x + 15, 455, 17, BLACK);
    DrawText("3: Greedy", x + 15, 485, 17, BLACK);
    DrawText("4: BFS", x + 15, 515, 17, BLACK);

    DrawText("R: Restart", x + 15, 545, 17, BLACK);

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
