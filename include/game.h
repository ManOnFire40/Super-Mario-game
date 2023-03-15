#ifndef GAME_H
#define GAME_H

#include "champion.h"
#include "Map.h"
#include "Mario.h"
#include "Luigi.h"


class Game{
public:
    Mario *c;
    Luigi *L;
    Map *board = new Map();
    bool play= true;
    bool ok= false;
public:
    Game(Mario c);
    Game(Luigi c);

    void move(int d,champion c);
    void check(champion* g);
    void clearAll();
    void remove(char in);
    ~Game(){
    }
};
#endif // GAME_H
