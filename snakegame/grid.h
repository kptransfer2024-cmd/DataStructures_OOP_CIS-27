#ifndef GRID_H
#define GRID_H

class Grid {
private:
    int rows;
    int cols;
    int cellSize;

public:
    Grid();

void draw() const;
    bool isInside(int row, int col) const;

    int getWidth() const;
    int getHeight() const;
};

#endif