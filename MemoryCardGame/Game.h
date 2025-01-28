#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "Player.h"
#include "Deck.h"

class Game {
private:
    Deck* d;
    Player* p1;
    Player* p2;
public:
    //constructors
    Game();
    Game(Deck* d, Player* p1, Player* p2);

    void initializeGame();
    int doubleBonus();
    int doublePenalty();
    void startGame();
    void endTurn();
    void gameOver();
    void playerTurn(Player* currentPlayer);
    void takeCardInput(int &rowCard1, int &columnCard1, string cardTurn);
    void displayScores();
    void cardLogic(Player *currentPlayer, int rowCard1, int columnCard1, Card *firstCard, Card *secondCard);

    //setters getters
    void setPlayer1(Player* p1);
    void setPlayer2(Player* p2);
    void setDeck(Deck* d);
    Deck* getDeck();
    Player* getPlayer1();
    Player* getPlayer2();

    //destructor
    ~Game();
};

#endif // GAME_H_INCLUDED
