#include "Card.h"
#include "StandardCard.h"
#include "PenaltyCard.h"
#include "BonusCard.h"
#include "Deck.h"
#include "Game.h"
#include "Player.h"

#include <iostream>

using namespace std;

int main()
{
    string name1, name2;
    cout << "Enter player 1's name: ";
    cin >> name1;
    cout << "Enter player 2's name: ";
    cin >> name2;

    Deck* d = new Deck();
    Player* p1 = new Player(name1, 0);
    Player* p2 = new Player(name2, 0);

    Game* game = new Game(d, p1, p2);

    game->startGame();

    delete game;
    return 0;
}