#ifndef PENALTYCARD_H_INCLUDED
#define PENALTYCARD_H_INCLUDED

#include "Card.h"

class PenaltyCard: public Card {
public:
    //constructors
    PenaltyCard();

    void display() override;
    bool isStandardCard() override;

    //destructor
    ~PenaltyCard();
};

#endif // PENALTYCARD_H_INCLUDED
