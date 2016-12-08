#ifndef PLAYER_H_
#define PLAYER_H_

#include <iostream>
#include <Deck.h>
#include <Hand.h>

using namespace std;

class Player : public Hand {
private:
	string name;
	int position;
	Card* chosenCard;
	string chosenCardValue;

protected:
	int previouslyChosenPlayerPosition;
	int chosenPlayerPosition;
	int playerType;
	
public:
	Player(string name, int position, int playerType);
	Player(Player& otherPlayer);
	string getName() const;   //Returns the name of the player
	Card* getChosenCard();
	int getChosenPlayerPosition();
	int getPosition();
	string getChosenCardValue() const;
	virtual void fetchFromDeck(Deck& deck, int amountToFetch);
	virtual ~Player();
	string toString();
	bool didIwin();
	virtual Card* chooseCardToRequest() = 0;
	Player* choosePlayerWithMostCards(vector<Player*>& players);
	Player* choosePlayerCyclicly(vector<Player*>& players, int previouslyChosenPlayerPosition);
	virtual Player* choosePlayer(vector<Player*>& players) = 0;
	virtual void goTurn(vector<Player *>& players, Deck& deck);
	virtual int getPreviouslyChosenPlayerPosition();
	int getPlayerType();
	void copy(Player& otherPlayer);
	Player& operator=(Player& otherPlayer);
};

class PlayerType1 : public Player {  //For strategy 1
public:
	PlayerType1(string name, int position);
	PlayerType1(Player& otherPlayerType1);
	Card* chooseCardToRequest();
	Player* choosePlayer(vector<Player*>& players);
};

class PlayerType2 : public Player {  //For strategy 2
public:
	PlayerType2(string name, int position);
	PlayerType2(Player& otherPlayerType2);
	Card* chooseCardToRequest();
	Player* choosePlayer(vector<Player*>& players);
};

class PlayerType3 : public Player {  //For strategy 3
public:
	PlayerType3(string name, int position);
	PlayerType3(Player& otherPlayerType3);
	Card* chooseCardToRequest();
	Player* choosePlayer(vector<Player*>& players);
};

class PlayerType4 : public Player {  //For strategy 4
public:
	PlayerType4(string name, int position);
	PlayerType4(Player& otherPlayerType4);
	Card* chooseCardToRequest();
	Player* choosePlayer(vector<Player*>& players);
};

#endif
