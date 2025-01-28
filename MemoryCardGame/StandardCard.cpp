#include "StandardCard.h"
#include "Card.h"
#include <iostream>

using namespace std;

//Standard card implementation
StandardCard::StandardCard() : Card(){
    
}
StandardCard::StandardCard(int n) : Card(n) {
 
}

void StandardCard::display() {
   
    if (this->getFaceUp()) {
        cout<<this->getNumber()<<" ";
    } else {
        cout<<"* ";
    }
}
bool StandardCard::isStandardCard() {
    return true;
}

StandardCard::~StandardCard() {
}