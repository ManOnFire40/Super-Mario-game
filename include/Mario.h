
#ifndef GAME_MARIO_H
#define GAME_MARIO_H
#include "champion.h"

class Mario : public champion{
public:
    Mario(int h,int g,int xloc, int yloc);
    void useAbility();


};
#endif //GAME_MARIO_H
