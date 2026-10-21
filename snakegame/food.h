#ifndef FOOD_H
#define FOOD_H

#include "gridStuff.h"
#include "grid.h"

class Food : public GridStuff {
private:
    bool isEaten;

public:
    Food();

    void draw() const;
    bool getIsEaten() const;
    void eliminate();
    void spawn(int headRow, int headCol, const int bodyRow[], const int bodyCol[], int bodyLength, const Grid& board);

};

#endif