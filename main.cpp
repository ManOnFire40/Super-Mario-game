#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<ctime>
#include <Windows.h>
#include "conio.h"
#include "Map.h"
#include "Champion.h"
#include "Mario.h"
#include "Luigi.h"

//#include "Point.h"
#include "game.h"
#include "Cell.h"

#define color SetConsoleTextAttribute |
using namespace std;
HANDLE hConsole =  GetStdHandle(STD_OUTPUT_HANDLE);
    Cell::Cell(char t,int xloc,int yloc)
    {
        type=t;
        x=xloc;
        y=yloc;
    }
Cell:: Cell(){
        type='.';
        x=0;
        y=0;
    }
int Cell:: getX() {
    return x;
}
int Cell::getY() {
    return y;
}
void Cell::setX(int x) {
    this->x = x;
}
void Cell::setY(int Y) {
    this->y = Y;
}

char Cell::getType()  {
    return type;
}

class Obstacle : public Cell {
protected:
    int damage;
public:
    Obstacle(int xloc, int yloc) : Cell('O', xloc, yloc) {
        damage = rand() % 5;
    }
    void execute(champion c){};
//    Obstacle() : Cell(){};
};
class Bomb : public Obstacle {
public:
    Bomb(int xloc, int yloc,int d) : Obstacle( xloc, yloc) {}
        void execute(champion c){
        c.setHealth(c.getHealth()-damage);
        cout<<"bomb executed with dmg ="<<damage<<endl;
    }
};
class Thief : public Obstacle {
public:
    Thief(int xloc, int yloc,int d) : Obstacle( xloc, yloc) {}
    void execute(champion c){
        c.setGemsScore(c.getGems_Score()-damage);
        cout<<"Thief executed with dmg ="<<damage<<endl;
    }
};
class Gem : public Cell {
protected:
    int points;
public:
    Gem(int xloc, int yloc) : Cell('G', xloc, yloc) {
        points = (rand() % 5)+5;
    }
    void execute(champion c){};
//    Gem() : Cell(){};
};
class Potion : public Gem {
public:
    Potion(int xloc, int yloc,int d) : Gem( xloc, yloc) {}
    void execute(champion c){
        c.setHealth(c.getHealth()-points);
        cout<<"Potion executed with points ="<<points<<endl;
    }
};
class Coin : public Gem {
public:
    Coin(int xloc, int yloc,int d) : Gem( xloc, yloc) {}
    void execute(champion c){
        c.setHealth(c.getHealth()-points);
        cout<<"Coin executed with points ="<<points<<endl;
    }
};
champion:: champion(int h,int g , int xloc, int yloc) :Cell('C',xloc,yloc){
    health=h;
    gems_score=g;
    x=xloc;
    y=yloc;
    c=2;
        cout<<"Constructor champion() is called"<<endl;

}
void champion:: print_champ_info() {
    cout << "health: " << health <<endl << "location: " << getX() <<" , "<<getY() << endl <<
    "gems_score: " << gems_score <<" / 400" << endl <<"Remaining Ability Moves:"<< c <<endl;
}
int champion::getHealth()  {
    return health;
}
int champion::getGems_Score() {
    return gems_score;
}
int champion::getC(){
    return c;
}
int champion:: getX() {
    return x;
}
int champion::getY() {
    return y;
}
void champion::setX(int x) {
    this->x = x;
}
void champion::setY(int Y) {
    this->y = Y;
}


void champion::setHealth(int health1) {
    if (health<=0){
        health=0;

    }
    champion::health = health1;
}
void champion::setGemsScore(int gemsScore) {
    gems_score = gemsScore;
}

void champion::useAbility(){}


   Mario::Mario(int h,int g,int xloc, int yloc) : champion(h,g, xloc, yloc) {
    }
    void Mario:: useAbility(){
        cout<<"Mario Ability is called"<<endl;
        c--;
    }



Luigi::Luigi(int h,int g,int xloc, int yloc) : champion(h,g, xloc, yloc) {
    }
    void Luigi::useAbility(){
        if (c!=0){
            c--;

            cout<<"Luigi Ability is called"<<endl;
        }
        else{
            cout<<"No abilities left"<<endl;
        }

    };



Map ::Map( ) {
    cout << "Constructor map() is called" << endl;
    board = new Cell * [10];
    for(int i =0; i < 10 ; i++){
        board[i]=new Cell[10];
    }

    randomize_map();
}
void Map ::print_map() {
    for (int a = 9; a >=0; a--) {
        for (int b = 0; b < 10; b++) {
                if(board[a][b].getType()==(char)232){
                    SetConsoleTextAttribute(hConsole, 3);
                }else if (board[a][b].getType()==(char)153){
                     SetConsoleTextAttribute(hConsole, 4);
                }
                else if(board[a][b].getType()== (char)234){
                    SetConsoleTextAttribute(hConsole, 6);
                }else
                 SetConsoleTextAttribute(hConsole, 13);
            cout << board[a][b].getType()<<" ";
        }
        cout << endl;
    }
    SetConsoleTextAttribute(hConsole, 2);
    cout << "print_map() is called" << endl;
    cout<< "----------------------------------"<<endl;


}
void Map :: print_map2() {
   for (int a = 9; a >=0; a--) {
        for (int b = 0; b < 10; b++) {
                if(board[a][b].getType()==(char)232){
                   SetConsoleTextAttribute(hConsole, 3);
                }else if (board[a][b].getType()==(char)153){
                     SetConsoleTextAttribute(hConsole, 4);
                }
                else if(board[a][b].getType()== (char)234){
                    SetConsoleTextAttribute(hConsole, 6);
                }else
                  SetConsoleTextAttribute(hConsole, 13);
            cout << board[a][b].getType()<<" ";
        }
        cout << endl;
    }
    SetConsoleTextAttribute(hConsole, 2);
    cout<< "----------------------------------"<<endl;

}
void Map :: randomize_map() {
    SetConsoleTextAttribute(hConsole, 2);
    cout << "randomize_map() is called" << endl;
    SetConsoleTextAttribute(hConsole, 6);
    cout << (char)234 << " Champion " <<endl ;
    SetConsoleTextAttribute(hConsole, 3);
    cout << (char)232 << " Gem , " <<endl;
          SetConsoleTextAttribute(hConsole, 4);
    cout << (char)153 << " obstacle  "<<endl;
    for (int a = 0; a < 10; a++) {
        for (int b = 0; b < 10; b++) {
             board[a][b] = *new Cell('.',a,b);
        }
    }

    srand(time(nullptr));
   board[0][0]= *new Cell (',',0,0) ;
    int ng = 0;
    int no = 0;
    while (ng < 40) {
        int r1 = rand() % 10 , r2 = rand() % 10 ;
        if (board[r1][r2].getType() == '.') {
            board[r1][r2] =(Cell) *new Gem(r1,r2);
            ng++;
        }
    }
    while (no < 20) {
        int r1 = rand() % 10 , r2 = rand() % 10 ;
        if (board[r1][r2].getType() == '.') {
            board[r1][r2] = (Cell)*new Obstacle(r1,r2);
            no++;
        }
    }

}
Game :: Game(Mario c) {
    this->c=&c;
    while (!ok) {
        board->board[0][0]=c;
        board->print_map();
        SetConsoleTextAttribute(hConsole, 11);
        c.print_champ_info();
        char input;
        cout << R"((press "y"for random map and "s" for starting the game))" << endl;
        cin >> input;
        if (input == 'y') {
            system("CLS");
            board->randomize_map();
        } else if (input == 's') {
            ok = true;
        }
        else {
            system("CLS");
        }
    }
    system("CLS");

    board->print_map2();
    SetConsoleTextAttribute(hConsole, 11);
    c.print_champ_info();
    move(1,c);
}

Game :: Game(Luigi c) {
    this->L=&c;
    while (!ok) {
        board->board[0][0]=c;
        board->print_map();
        SetConsoleTextAttribute(hConsole, 11);
        c.print_champ_info();
        char input;
        cout << R"((press "y"for random map and "s" for starting the game))" << endl;
        cin >> input;
        if (input == 'y') {
            system("CLS");
            board->randomize_map();
        } else if (input == 's') {
            ok = true;
        }
        else {
            system("CLS");
        }
    }
    system("CLS");

    board->print_map2();
    SetConsoleTextAttribute(hConsole, 11);
    c.print_champ_info();
    move(1,c);
}
void Game :: move (int d,champion c){
    while (play) {
        cout<<"p "<<play<<endl;
        cout << "please enter motion direction: 8-up 4-Left,6-right,2-down,x-for ability" << endl;
        char in=getch();

    switch (in) {
        case '8':
            if (c.getX()+d <= 9) {
                if (board->board[c.getX() + d][c.getY()].getType() == 'G') {
                    c.setGemsScore(c.getGems_Score() + 10);

                } else if (board->board[c.getX() + d][c.getY()].getType() =='O') {
                    c.setHealth(max(0,c.getHealth() - 40));

                }
                board->board[c.getX()][c.getY()] = *new Cell('.',c.getX(),c.getY());

                board->board[c.getX() + d][c.getY()] = c;
                c.setX(c.getX() + d);
                c.setY(c.getY());

            }
            system("CLS");
            board->print_map2();
            SetConsoleTextAttribute(hConsole, 11);
            c.print_champ_info();
            check(&c);

            break;
        case '2':
            if (c.getX()-d >= 0) {
                if (board->board[c.getX() - d][c.getY()].getType() == 'G') {
                    c.setGemsScore(c.getGems_Score() + 10);

                } else if (board->board[c.getX() - d][c.getY()].getType() == 'O') {
                    c.setHealth(max(0,c.getHealth() - 40));
                }
                board->board[c.getX()][c.getY()] = *new Cell('.',c.getX(),c.getY());

                board->board[c.getX() - d][c.getY()] = c;
                c.setX(c.getX() - d);
                c.setY(c.getY());

            }
            system("CLS");
            board->print_map2();
            SetConsoleTextAttribute(hConsole, 11);
            c.print_champ_info();
            check(&c);

            break;
        case '6':
            if (c.getY()+d <= 9) {
                if (board->board[c.getX()][c.getY() + d].getType() == 'G') {
                    c.setGemsScore(c.getGems_Score() + 10);
                }
                else if (board->board[c.getX()][c.getY() + d].getType() == 'O') {
                    c.setHealth(max(0,c.getHealth() - 40));
                }
                board->board[c.getX()][c.getY()] = *new Cell('.',c.getX(),c.getY());

                board->board[c.getX()][c.getY() + d] = c;
                c.setX(c.getX());
                c.setY(c.getY()+d);

            }
            system("CLS");
            board->print_map2();
            SetConsoleTextAttribute(hConsole, 11);
            c.print_champ_info();
            check(&c);

            break;
        case '4':
            if (c.getY()-d >= 0) {
                if (board->board[c.getX()][c.getY() - d].getType() == 'G') {
                    c.setGemsScore(c.getGems_Score() + 10);
                }
                else if (board->board[c.getX()][c.getY() - d].getType() =='O') {
                    c.setHealth(max(0,c.getHealth() - 40));
                }
                board->board[c.getX()][c.getY()] = *new Cell('.',c.getX(),c.getY());

                board->board[c.getX()][c.getY() - d] = c;
                c.setX(c.getX());
                c.setY(c.getY()-d);

            }
            system("CLS");
            board->print_map2();
            SetConsoleTextAttribute(hConsole, 11);
            c.print_champ_info();
            check(&c);
            break;
        case 'x':

            if (c.getC()!=0) {
                c.useAbility();
                system("CLS");
                board->print_map2();
                SetConsoleTextAttribute(hConsole, 11);
                c.print_champ_info();
                check(&c);

                move(2, c);
            }
            else
                cout<<"No more Abilities"<<endl;
            break;
        default:{
            char in=getch();
            if(in == '0'){
                exit(0);
            }
            move(1,c);
        }
    }
}
}
void Game::remove(char in) {
         int i = c->getX();
         int j = 0;
         for (j = c->getY(); j < 10; ++j) {
             if (board->board[i][j].getType() == 'O') {
                 board->board[i][j] = *new Cell('.', i, j);
             }
         }

             j = c->getY();
            for (int i = c->getX(); j < 10; ++j) {
                if (board->board[i][j].getType() == 'O') {
                    board->board[i][j] = *new Cell('.', i, j);
                }
            }
        }
void Game::check(champion *g){
    if (g->getHealth() <= 0) {
        SetConsoleTextAttribute(hConsole, 4);
        cout << "Game over!"<<endl;
        play= false;
    }
    if (g->getGems_Score()==400){
         SetConsoleTextAttribute(hConsole, 3);
        cout<< "YOU WON!"<<endl;
        play= false;
    }
}
void Game::clearAll(){

}
int main() {
    char input;
    cout << R"((press "M"for Mario champion and "L" for Luigi champion))" << endl;
    cin >> input;
    system("CLS");
    SetConsoleTextAttribute(hConsole,2);
    if (input=='M') {
        Mario M = *new Mario(100,0,0,0);
        Game g = *new Game(M);
    }
    else if (input=='L')
        Game g = *new Game(*new Luigi(100,0,0,0));

    getch();
   // delete g ;
    SetConsoleTextAttribute(hConsole,7);
    return 0;
}

