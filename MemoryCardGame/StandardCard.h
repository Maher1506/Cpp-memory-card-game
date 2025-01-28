#ifndef STANDARDCARD_H_INCLUDED
#define STANDARDCARD_H_INCLUDED

#include "Card.h"

class StandardCard: public Card {


public:
    //constructors
    StandardCard();
    StandardCard(int n);

    void display() override;
    bool isStandardCard() override;

    //destructor
    ~StandardCard();
};

#endif // STANDARDCARD_H_INCLUDED
