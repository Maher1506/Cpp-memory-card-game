#include "Card.h"
#include <iostream>

using namespace std;

//Card implementation

//Constructors
Card::Card() {
    faceUp = false;
}
Card::Card(int n) {
    this->number = n;
    faceUp = false;
}

//Gameplay methods
void Card::reveal() {
    faceUp = true;
}
void Card::hide() {
    faceUp = false;
}

//Setters and getters
int Card::getNumber() {
    return  number;
}
void Card::setNumber(int n) {
    number = n;
}
void Card::setFaceUp(bool f) {
    faceUp = f;
}
bool Card::getFaceUp() {
    return faceUp;
}

//Destructor
Card::~Card() {
}