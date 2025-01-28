#include "Player.h"
#include <iostream>

using namespace std;

//Player implementation
Player::Player() {
    name = "";
    score = 0;
    skipped = false;
}
Player::Player(string n, int s) {
    name = n;
    score = s;
    skipped = false;
}
void Player::displayScore() {
    cout<<"Player: "<<name<<" Score: "<<score<<endl;
}
string Player::getName() {
    return name;
}
int Player::getScore() {
    return score;
}
void Player::setName(string name) {
    this->name = name;
}
void Player::setScore(int score) {
    this->score = score;
}
bool Player::isSkipped() {
    return skipped;
}
void Player::setSkipped(bool state) {
    skipped = state;
}
void Player::incScore() {
    score++;
}
void Player::decScore() {
    score--;
}
Player::~Player() {
}