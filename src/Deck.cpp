#include <Deck.h>

//Deck Constructor
Deck::Deck(vector<Card*>& deck):
deck(deck)
{}

Deck::Deck(const Deck& deck):
deck(deck.getDeck())

{}

bool Deck::isEmpty(){
	return this->deck.empty();
}

int Deck::getNumberOfCards(){
	return deck.size();
}

string Deck::toString(){
	string strDeck = "";
	for(vector<Card*>::iterator it = deck.begin() ; it != deck.end(); it++){
		strDeck += (*it)->toString() + " ";
	}
	int strDeckLength = strDeck.length();
	string strDeckNoLastSpace = strDeck.substr(0, strDeckLength-1);
	return strDeckNoLastSpace;
}

Deck::~Deck(){
	for(vector<Card*>::iterator it = deck.begin() ; it != deck.end(); it++){
		delete (*it);
	}
}

Card* Deck::fetchCard(){
	if (!this->isEmpty()){
		Card* topCard = this->deck.front();
		this->deck.erase(deck.begin());
		return topCard;
	}
	throw invalid_argument("Trying to fetch from empty deck!!!");
}

vector<Card*> Deck::giveCards(int numberToGive){
	vector<Card*> cardsToGive;
	if (numberToGive < 0){
		throw invalid_argument("Can't fetch negative cards");
	}
	else if (numberToGive == 0){
		return cardsToGive;
	}
	for (int i=0; i<numberToGive && !this->isEmpty(); i++){
		cardsToGive.push_back(this->fetchCard());
	}
	return cardsToGive;
}

// Deck::Deck(const Deck& otherDeck) {
// 	Deck deck(otherDeck.getDeck());
// 	return deck;
// }

vector<Card*> Deck::getDeck() const {

	return this->deck;
}

