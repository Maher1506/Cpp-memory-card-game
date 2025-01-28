#include "Deck.h"
#include "Card.h"
#include "BonusCard.h"
#include "PenaltyCard.h"
#include "StandardCard.h"

#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

//Deck implementation
Deck::Deck() {
    // create all rows and columns
    grid = new Card**[4];  // pointer to rows
    for (int i = 0; i < 4; i++) {
        Card** row = new Card*[4];
        grid[i] = row;
    }

    // populate deck with standard numbers
    int cardNumber = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (j%2 == 0) {
                cardNumber++;
            }
            Card* c = new StandardCard (cardNumber);
            grid[i][j] = c;
        }
    }

    // populate deck with bonus and penalty
    grid[3][0] = new BonusCard();
    grid[3][1] = new BonusCard();
    grid[3][2] = new PenaltyCard();
    grid[3][3] = new PenaltyCard();
}

void Deck::shuffle() {
    //bafady f 1d array
    Card** flatArray = new Card*[16];

    int index = 0;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            flatArray[index++] = grid[i][j];
        }
    }

    int x = time(0);
    srand(x);
    //ba shuffle el 1d array
    for (int i = 0; i < 16; i++) {
        int rnd = rand() % 16;
        Card* tmp = flatArray[rnd];
        flatArray[rnd] = flatArray[i];
        flatArray[i] = tmp;
    }

    // baraga3 el values el grid
    index = 0;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            grid[i][j] = flatArray[index++];
        }
    }

    delete[] flatArray;
}
void Deck::displayGrid() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            grid[i][j]->display();
        }
        cout<<endl;
    }
}
bool Deck::gameFinished() {
    int c = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (!grid[i][j]->getFaceUp()) {
                c++;
            }
        }
    }

    return c <= 1;
}

Card*** Deck::getGrid() {
    return grid;
}
void Deck::setGrid(Card*** grid) {
    this->grid = grid;
}

Deck::~Deck() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            delete grid[i][j]; // delete each card
        }
        delete[] grid[i]; // delete each row
    }
    delete[] grid;  // delete grid
}