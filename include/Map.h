#ifndef MAP_H
#define MAP_H

#include "Cell.h"
#include "champion.h"


class Map {
public:
    int rows;
    int columns;
    Cell** board;
public:
    Map();
    void randomize_map();
    void print_map();

    void print_map2();
};
#endif // MAP_H
