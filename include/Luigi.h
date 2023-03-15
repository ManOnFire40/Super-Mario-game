

#ifndef GAME_LUIGI_H
#define GAME_LUIGI_H

#include "champion.h"

class Luigi : public champion{
public:
    Luigi(int h,int g,int xloc, int yloc);
    void useAbility();


};
#endif //GAME_LUIGI_H
