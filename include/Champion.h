#ifndef CHAMPION_H
#define CHAMPION_H

#include <iostream>
#include "Cell.h"
#include "Map.h"
class champion : public Cell {
protected:

    int health;
    int gems_score;
    int x;
    int y;
    int c;
public:
    champion(int h, int g, int xloc, int yloc);

    void print_champ_info();
    int getHealth();
    int getGems_Score();
    int getX();
    int getY();
    int getC();
    void setHealth(int health);
    void setGemsScore(int gemsScore);
    virtual void useAbility();
    ~champion(){
    }

    void setX(int x);

    void setY(int Y);
};
#endif // CHAMPION_H
