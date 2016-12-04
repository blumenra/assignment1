#ifndef DECK_H_
#define DECK_H_

#include <iostream>
#include <vector>

#include <Card.h>

using namespace std;


class Deck {
private:
	// Declared here the collection of "Card *" of the deck
	vector<Card*> deck;

public:
	Deck(vector<Card*>& deck);
	bool isEmpty();
	Card* fetchCard();   //Returns the top card of the deck and remove it rom the deck
	int getNumberOfCards(); // Get the number of cards in the deck
	string toString(); // Return the cards in top-to-bottom order in a single line, cards are separated by a space ex: "12S QD AS 3H"
	vector<Card*> giveCards(int numberToGive);
	~Deck();
};

#endif
