#ifndef GRIDSTUFF_H
#define GRIDSTUFF_H

#include "grid.h"

class GridStuff {
protected:
    int row;
    int col;
    int cellSize = 30;

public:
    GridStuff(int row0, int col1);
    int getRow() const;
    int getCol() const;
};


#endif