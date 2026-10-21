#include <iostream>
#include <string>

#include "gridStuff.h"

GridStuff::GridStuff(int row0, int col1) {
    row = row0;
    col = col1;
}


int GridStuff::getRow() const {
        return row;
    }

int GridStuff::getCol() const {
return col;
    }