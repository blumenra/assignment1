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

public:
	Player(string name, int position);
	string getName() const;   //Returns the name of the player
	int getPosition() const;
	virtual void fetchFromDeck(Deck& deck, int amountToFetch);
	virtual ~Player();
	string toString();
	bool didIwin();
	virtual Card* chooseCardToRequest() = 0;
	Player* choosePlayerWithMostCards(vector<Player*> players);
	virtual Player* choosePlayer(vector<Player*> players) = 0;
};

class PlayerType1 : public Player {  //For strategy 1
public:
	PlayerType1(string name, int position);
	Card* chooseCardToRequest();
	Player* choosePlayer(vector<Player*> players);
};

class PlayerType2 : public Player {  //For strategy 2
//...
};

class PlayerType3 : public Player {  //For strategy 3
//...
private:
	int previouslyChosenPlayerPosition;
};

class PlayerType4 : public Player {  //For strategy 4
//...
private:
	int previouslyChosenPlayerPosition;
};

#endif
