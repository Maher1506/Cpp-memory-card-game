#include "BonusCard.h"
#include "Card.h"
#include <iostream>

using namespace std;

//Bonus card implementation
BonusCard::BonusCard() : Card(7) {
}

void BonusCard::display() {
    if (getFaceUp()) {
        cout<< getNumber() << " ";
    } else {
        cout<<"* ";
    }
}
bool BonusCard::isStandardCard() {
    return false;
}

BonusCard::~BonusCard() {
}