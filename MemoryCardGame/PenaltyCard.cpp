#include "PenaltyCard.h"
#include "Card.h"

#include <iostream>

using namespace std;

//Penalty card implementation
PenaltyCard::PenaltyCard() : Card(8) {
}

void PenaltyCard::display() {
    if (getFaceUp()) {
        cout<< getNumber() << " ";
    } else {
        cout<<"* ";
    }
}
bool PenaltyCard::isStandardCard() {
    return false;
}

PenaltyCard::~PenaltyCard() {
}