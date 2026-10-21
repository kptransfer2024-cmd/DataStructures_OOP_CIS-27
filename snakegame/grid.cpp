#include <iostream>
#include <string>

#include "grid.h"
#include "raylib.h"
using namespace std;

Grid::Grid() {
    rows = 20;
    cols = 20;
    cellSize = 30;
}

void Grid::draw() const {
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            int x = col * cellSize;
            int y = row * cellSize;

            DrawRectangleLines(
                x, y, cellSize, cellSize, LIGHTGRAY
            );
        }
    }
}

bool Grid::isInside(int row, int col) const {
    return row >= 0 && row < rows &&
            col >= 0 && col < cols;
}

int Grid::getWidth() const {
    return cols * cellSize;
}

int Grid::getHeight() const {
    return rows * cellSize;
}