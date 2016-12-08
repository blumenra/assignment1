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
	vector<string> configFileVec;
	bool verbal;
	int highestNumericValue;
	int turn;
	vector<Player *> players;  //The list of the players
	vector<Player *> winners;
	Deck deck;                 //The deck of the game

	vector<string> parseConfigFile(char* configurationFile);
	vector<Card*> deckCreator(string parsedDeck);
	Shape stringToShape(string strShape);
	Figure stringToFigure(string strFigure);
	bool isFigure(string value);
	vector<Player *> playersCreator(vector<string> configFileVec);
	void deal();
public:
	Game(char* configurationFile);
	Game(const Game& otherGame);
	void init();
	void play();
	void printState();        //Print the state of the game as described in the assignment.
	void printWinner();       //Print the winner of the game as describe in the assignment.
    void printNumberOfTurns(); //Print the number of played turns at any given time.  
	bool isVerbal() const;
	bool areWinners();
	bool singleWinner();
	vector<Player *> getPlayers() const;
	void printTurn();
	int getHighestNumericValue() const;
	int getTurn() const;
	Deck getDeck() const;
	vector<Player *> getWinners() const;
	void copy(const Game& otherGame);
	~Game();
};

#endif
