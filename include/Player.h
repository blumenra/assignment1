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
	Player* chosenPlayer;
	Card* chosenCard;

public:
	Player(string name, int position);
	string getName() const;   //Returns the name of the player
	int getPosition() const;
	virtual void fetchFromDeck(Deck& deck, int amountToFetch);
	virtual ~Player();
	string toString();
	bool didIwin();
	virtual Card* chooseCardToRequest() = 0;
	// virtual Player* choosePlayer(vector<Player*>) = 0;
};

class PlayerType1 : public Player {  //For strategy 1
public:
	PlayerType1(string name, int position);
	Card* chooseCardToRequest();
};

class PlayerType2 : public Player {  //For strategy 2
//...
};

class PlayerType3 : public Player {  //For strategy 3
//...
};

class PlayerType4 : public Player {  //For strategy 4
//...
};

#endif
