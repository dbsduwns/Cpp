#include<iostream>
#include<string>
#include <cstdlib>
#include <ctime>
using namespace std;

class Player {
    string name;
public:
    void setName(string name);
    string getName();
};

class GamblingGame {
    Player* p = new Player[2];
public:
    GamblingGame();
    void nameSet();
    string random(string n);
    void startGame();
    ~GamblingGame();
};