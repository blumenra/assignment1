#ifndef GAME_H_
#define GAME_H_

#include <iostream>
#include <sstream>
#include <fstream>

#include "Player.h"
#include "Deck.h"

using namespace std;

class Game {
private:
	vector<Player *> players;  //The list of the players
	Deck deck;                 //The deck of the game
	int turn;
	bool verbal;
	vector<Player *> winners;
	int highestNumericValue;

	vector<string> parseConfigFile(char* configurationFile);
	vector<Card*> cardsForDeckCreator(string parsedDeck);
	Shape stringToShape(string strShape);
	Figure stringToFigure(string strFigure);
	bool isFigure(string value);
public:
	Game(char* configurationFile);
	void init();
	void play();
	void printState();        //Print the state of the game as described in the assignment.
	void printWinner();       //Print the winner of the game as describe in the assignment.
    void printNumberOfTurns(); //Print the number of played turns at any given time.  
};

#endif
