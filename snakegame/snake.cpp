#include <iostream>
#include <string>

#include "gridStuff.h"
#include "snake.h"
#include "raylib.h"
using namespace std;

Snake::Snake() : GridStuff(4, 4) {
    isAlive = true;

    bodyLength = 2;

    bodyRow[0] = row;
    bodyCol[0] = col - 1;

    bodyRow[1] = row;
    bodyCol[1] = col - 2;

    tailRow = bodyRow[bodyLength - 1];
    tailCol = bodyCol[bodyLength - 1];

}


const int* Snake::getBodyRow() const {
    return bodyRow;
}

const int* Snake::getBodyCol() const {
    return bodyCol;
}

int Snake::getBodyLength() {
    return bodyLength;
}


void Snake::drawHead() const {
    int x = col * cellSize;
    int y = row * cellSize;


    DrawRectangle(x, y, cellSize, cellSize, GREEN);

}

void Snake::drawBody() const {
    for (int i = 0; i < bodyLength; i++){
        int x_i = bodyCol[i] * cellSize;
        int y_i = bodyRow[i] * cellSize;
        DrawRectangle(x_i, y_i, cellSize, cellSize, YELLOW);
    }
}

int Snake::move(int rowChange, int colChange, const Grid& board) {
    if (!isAlive) {
        return -1;
    }
    int newRow = row + rowChange;
    int newCol = col + colChange;

    if (!board.isInside(newRow, newCol)) {
        isAlive = false;
        return -1;
    }

    if (rowChange == 0 && colChange == 0) {
        return 0;
    }

    if (bodyLength > 0 &&  newRow == bodyRow[0] && newCol == bodyCol[0]) {
        return 0;
    }

    else {
        tailRow = bodyRow[bodyLength - 1];
        tailCol = bodyCol[bodyLength - 1];
        for (int i = bodyLength - 1; i > 0; i--) {
            bodyRow[i] = bodyRow[i - 1];
            bodyCol[i] = bodyCol[i - 1];
        }
        if (bodyLength > 0) {
            bodyRow[0] = row;
            bodyCol[0] = col;
        }
        row = newRow;
        col = newCol;
    
        for (int i = 0; i < bodyLength; i++) {
            if (row == bodyRow[i] && col == bodyCol[i]) {
                isAlive = false;
                return -1;
            }
        }
        return 1;
    }
}

void Snake::eat() {
    cout << "ate it!" << endl;
    bodyLength ++;
    bodyRow[bodyLength - 1] = tailRow;
    bodyCol[bodyLength - 1] = tailCol;

}


bool Snake::getIsAlive() const {
    return isAlive;
}
