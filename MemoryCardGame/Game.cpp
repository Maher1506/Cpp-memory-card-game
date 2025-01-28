#include "Game.h"
#include "Player.h"
#include "Deck.h"
#include "Card.h"
#include "StandardCard.h"
#include "BonusCard.h"
#include "PenaltyCard.h"

#include <iostream>
#include <limits>

using namespace std;

//Game implementation
Game::Game() {
    d = new Deck();
    p1 = new Player();
    p2 = new Player();
}
Game::Game(Deck* d, Player* p1, Player* p2) {
    this->d = d;
    this->p1 = p1;
    this->p2 = p2;
}

void Game::initializeGame() {
    d->shuffle();
    d->displayGrid();
}
void Game::playerTurn(Player* currentPlayer) {
    if (d->gameFinished())
        return;
    // Check if the player is suppossed to skip this turn
    if (currentPlayer->isSkipped()) {
        cout << currentPlayer->getName() << " Skips this turn" << endl;
        currentPlayer->setSkipped(false);
        endTurn();
        return;
    }

    int rowCard1, columnCard1, rowCard2, columnCard2;

    cout << currentPlayer->getName() << ", it's your turn!" << endl;
    d->displayGrid();

    // Handle input for the first card
    takeCardInput(rowCard1, columnCard1, "first");

    while (d->getGrid()[rowCard1-1][columnCard1-1]->getFaceUp()) {
        cout << "Card already matched. Chose another one" << endl;
        takeCardInput(rowCard1, columnCard1, "first");
    }

    Card* firstCard = d->getGrid()[rowCard1-1][columnCard1-1];
    firstCard->reveal();

    d->displayGrid();

    // Handle input for the second card
    takeCardInput(rowCard2, columnCard2, "second");

    while (d->getGrid()[rowCard2-1][columnCard2-1]->getFaceUp()) {
        cout << "Card already matched. Chose another one" << endl;
        takeCardInput(rowCard2, columnCard2, "second");
    }

    Card* secondCard = d->getGrid()[rowCard2-1][columnCard2-1];
    secondCard->reveal();

    d->displayGrid();
    
    // Check Card condtions
    cardLogic(currentPlayer, rowCard1, columnCard1, firstCard, secondCard);
}

void Game::cardLogic(Player *currentPlayer, int rowCard1, int columnCard1, Card *firstCard, Card *secondCard) {
    // both cards are standard cards
    if (firstCard->isStandardCard() && secondCard->isStandardCard()) {
        if (firstCard->getNumber() == secondCard->getNumber()) {
            cout << "Match found! You earn 1 point." << endl;
            currentPlayer->incScore();
            cout << "You get another turn!" << endl;
            displayScores();
            playerTurn(currentPlayer);
        }
        else {
            cout << "The cards do not match" << endl;
            firstCard->hide();
            secondCard->hide();
            endTurn();
            return;
        }
    
    } else {
        // Cards are not both standard check for bonus and penalty scenarios.
        bool firstBonus = (firstCard->getNumber() == 7);
        bool secondBonus = (secondCard->getNumber() == 7);
        bool firstPenalty = (firstCard->getNumber() == 8);
        bool secondPenalty = (secondCard->getNumber() == 8);

        if ((firstBonus && secondPenalty) || (firstPenalty && secondBonus) ) {
            // Penalty + Bonus
            cout << "A Penalty and Bonus cards are revealed" << endl;
            cout << "No effect applied" << endl;
            endTurn();
            return;
        } 
         else if (firstBonus && secondBonus) {
            // Two bonus cards
            int r = doubleBonus();
            if (r == 1) {
                currentPlayer->incScore();
                displayScores();
                playerTurn(currentPlayer);
            } else if (r == 2) {
                currentPlayer->incScore();
                currentPlayer->incScore();
                endTurn();
                return;
            }
        } else if (firstPenalty && secondPenalty) {
            // Two penalty cards
            int r = doublePenalty();
            if (r == 1) {
                currentPlayer->decScore();
                currentPlayer->setSkipped(true);

                endTurn();
                return;
            } else if (r == 2) {
                currentPlayer->decScore();
                currentPlayer->decScore();
                endTurn();
                return;
            }
        } else if (firstBonus || secondBonus) {
            // Bonus + Standard
            cout << "Bonus Card revealed!" << endl;
            cout << "You get a point" << endl;
            currentPlayer->incScore();

            // Hide the standard card (the one that's not bonus)
            if (firstBonus) {
                secondCard->hide();
            } else {
                firstCard->hide();
            }
            endTurn();
            return;
        } else if (firstPenalty || secondPenalty) {
            // Penalty + Standard
            cout << "Penalty Card revealed" << endl;
            cout << "You are deducted a point" << endl;
            currentPlayer->decScore();

            // hide the standard card
            if (firstPenalty) {
                secondCard->hide();
            } else {
                firstCard->hide();
            }
            endTurn();
            return;
        }
    }
}

void Game::takeCardInput(int &rowCard, int &columnCard, string cardTurn) {
    cout << "Enter " + cardTurn + " card row (1-4):";
    cin >> rowCard;
    while (rowCard < 1 || rowCard > 4) {
        cout << "Out Of Bounds" << endl;
        cout << "Enter " + cardTurn + " card row (1-4):";
        cin >> rowCard;
    }

    cout << "Enter " + cardTurn + " card column (1-4):";
    cin >> columnCard;
    while (columnCard < 1 || columnCard > 4) {
        cout << "Out Of Bounds" << endl;
        cout << "Enter " + cardTurn + " card column (1-4):";
        cin >> columnCard;
    }
}

void Game::endTurn() {
    displayScores();

    std::cout << "\nPress Enter to continue";
    fgetc(stdin);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void Game::displayScores() {
    cout << p1->getName() << " Score: " << p1->getScore() << endl;
    cout << p2->getName() << " Score: " << p2->getScore() << endl;
}

int Game:: doubleBonus() {
    int r = 0;
    cout << "2 Bonus cards matched!" << endl;
    cout << "For gaining 1 point and taking another turn insert 1" << endl;
    cout << "For gaining 2 points insert 2" << endl;
    cin >> r;
    while (!r == 1 || !r == 2) {
        cout << "please enter either 1 or 2" << endl;
        cin >> r;
    }
    return r;
}

int Game:: doublePenalty() {
    int r = 0;
    cout << "2 Penalty cards matched!" << endl;
    cout << "For losing 1 point and skipping your turn insert 1" << endl;
    cout << "For losing 2 points insert 2" << endl;
    cin >> r;
    while (!r == 1 || !r == 2) {
        cout << "please enter either 1 or 2" << endl;
        cin >> r;
    }
    return r;
}

void Game::startGame() {
    initializeGame();
    while (!d->gameFinished()) {
        playerTurn(p1);
        playerTurn(p2);
    }
    cout << "Game Over!" << endl;
    gameOver();
}

void Game::gameOver() {
    cout << "Final Scores: " << endl;
    cout << p1->getName() << ": " << p1->getScore() << endl << p2->getName() << ": " << p2->getScore() << endl;
    if (p1->getScore() > p2->getScore()) {
        cout << "THE WINNER IS " << p1->getName() << endl;
    }

    else if (p2->getScore() > p1->getScore()) {
        cout << "THE WINNER IS " << p2->getName() << endl;
    }
    else {
        cout << "IT'S A TIE! " << endl;
    }
    
}

void Game::setPlayer1(Player* p1) {
    this->p1 = p1;
}
void Game::setPlayer2(Player* p2) {
    this->p2 = p2;
}
void Game::setDeck(Deck* d) {
    this->d = d;
}
Deck* Game::getDeck() {
    return d;
}
Player* Game::getPlayer1() {
    return p1;
}
Player* Game::getPlayer2() {
    return p2;
}

Game::~Game() {
    delete d;
    delete p1;
    delete p2;
}