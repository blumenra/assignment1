#ifndef PLAYER_H_
#define PLAYER_H_

#include <iostream>
#include <Deck.h>
#include <Hand.h>

using namespace std;

class Player : public Hand {
private:
	const string name;
	const int position;
	Card* chosenCard;
	Player* chosenPlayer;

public:
	Player(string name, int position);
	string getName() const;   //Returns the name of the player
	Card* getChosenCard();
	Player* getChosenPlayer();
	int getPosition() const;
	virtual void fetchFromDeck(Deck& deck, int amountToFetch);
	virtual ~Player();
	string toString();
	bool didIwin();
	virtual Card* chooseCardToRequest() = 0;
	Player* choosePlayerWithMostCards(vector<Player*>& players);
	Player* choosePlayerCyclicly(vector<Player*>& players, int previouslyChosenPlayerPosition);
	virtual Player* choosePlayer(vector<Player*>& players) = 0;
	virtual void goTurn(vector<Player *>& players, Deck& deck);
};

class PlayerType1 : public Player {  //For strategy 1
public:
	PlayerType1(string name, int position);
	Card* chooseCardToRequest();
	Player* choosePlayer(vector<Player*>& players);
};

class PlayerType2 : public Player {  //For strategy 2
public:
	PlayerType2(string name, int position);
	Card* chooseCardToRequest();
	Player* choosePlayer(vector<Player*>& players);
};

class PlayerType3 : public Player {  //For strategy 3
private:
	int previouslyChosenPlayerPosition;
public:
	PlayerType3(string name, int position);
	Card* chooseCardToRequest();
	Player* choosePlayer(vector<Player*>& players);
};

class PlayerType4 : public Player {  //For strategy 4
//...
private:
	int previouslyChosenPlayerPosition;
public:
	PlayerType4(string name, int position);
	Card* chooseCardToRequest();
	Player* choosePlayer(vector<Player*>& players);
};

#endif
