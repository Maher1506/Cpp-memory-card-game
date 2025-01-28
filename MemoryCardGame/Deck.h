#ifndef DECK_H_INCLUDED
#define DECK_H_INCLUDED

#include "Card.h"

class Deck {
private:
    Card*** grid;

public:
    //constructors
    Deck();

    void shuffle();
    void displayGrid();
    bool gameFinished();

    //setter getter
    Card*** getGrid();
    void setGrid(Card*** grid);

    //destructor
    ~Deck();
};

#endif // DECK_H_INCLUDED
