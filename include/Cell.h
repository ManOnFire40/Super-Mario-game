

#ifndef GAME_CELL_H
#define GAME_CELL_H
#include <iostream>


class Cell {
private:
    char type;
    int x ;
    int y;
public:
    Cell(char t,int xloc,int yloc);
    Cell();
    int getX();

    char getType() ;

    int getY();
    void setY(int y);
    void setX(int x);
};


#endif //GAME_CELL_H
