#include <iostream>
#include <string>
#include <cstdlib>
#include "gridStuff.h"
#include "food.h"
#include "grid.h"
#include "raylib.h"
using namespace std;


Food::Food() : GridStuff(2, 17) {
    isEaten = false;
}


bool Food::getIsEaten() const {
    return isEaten;
}

void Food::draw() const {
    int x = col * cellSize + cellSize / 2;
    int y = row * cellSize + cellSize / 2;

    DrawCircle(x, y, cellSize / 3.0f, RED);
}


void Food::eliminate() {
    isEaten = true;
}


void Food::spawn(int headRow, int headCol, const int bodyRow[], const int bodyCol[], int bodyLength, const Grid& board) {
    int boardWidth = board.getWidth() / cellSize;
    int boardHeight = board.getHeight() / cellSize;
    
    int newRow = rand() % boardHeight;
    int newCol = rand() % boardWidth;
    for (int i = 0; i < bodyLength; i++){
        if ((newRow == bodyRow[i] && newCol == bodyCol[i]) || (newRow == headRow && newCol == headCol)) {
            if (newRow < boardHeight - 3 && newCol < boardWidth - 3) { 
            newRow += rand() % 3;
            newCol += rand() % 3;
            }
            else if (newRow > 3 && newCol > 3) {
                newRow -= rand() % 3;
                newCol -= rand() % 3;
            }
            else {
                newRow = rand() % boardHeight;
                newCol = rand() % boardWidth;
            }
            i = -1;
        }
    }
    row = newRow;
    col = newCol; 

    isEaten = false;
}



