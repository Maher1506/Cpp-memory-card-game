#ifndef BONUSCARD_H_INCLUDED
#define BONUSCARD_H_INCLUDED

#include "Card.h"

class BonusCard: public Card {
public:
    //constructors
    BonusCard();

    void display() override;
    bool isStandardCard() override;

    //destructor
    ~BonusCard();
};

#endif // BONUSCARD_H_INCLUDED
