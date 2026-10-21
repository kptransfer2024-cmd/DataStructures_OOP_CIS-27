#ifndef SNAKE_H
#define SNAKE_H

#include "gridStuff.h"
#include "grid.h"

class Snake : public GridStuff {
private:
    bool isAlive;


    int bodyLength;
    int bodyRow[400];
    int bodyCol[400];

    int tailRow;
    int tailCol;


public:
    Snake();
    const int* getBodyRow() const;
    const int* getBodyCol() const;
    int getBodyLength();

    void drawHead() const;
    void drawBody() const;
    int move(int rowChange, int colChange, const Grid& board);
    void eat();
    bool getIsAlive() const;
};

#endif