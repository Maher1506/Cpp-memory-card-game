#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <iostream>

using namespace std;

class Player {
private:
    string name;
    int score;
    bool skipped;
public:
    //constructors
    Player();
    Player(string n, int s);

    void displayScore();

    //setter getter
    string getName();
    int getScore();
    void incScore();
    void decScore();

    void setName(string name);
    void setScore(int score);

    bool isSkipped();
    void setSkipped(bool state);

    //destructor
    ~Player();
};

#endif // PLAYER_H_INCLUDED
