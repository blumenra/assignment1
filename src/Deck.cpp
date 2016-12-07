#include <Deck.h>

//Deck Constructor
Deck::Deck(vector<Card*>& deck):
deck(deck)
{}

Deck::Deck(const Deck& otherDeck) {
	// cout << "otherDeck before copy: " << otherDeck.toString() << endl;
	this->copy(otherDeck);
}

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

// void DecK::deleteDeck() {

// 	for(vector<Card*>::iterator it = deck.begin() ; it != deck.end(); it++){
// 		delete (*it);
// 	}
// }

vector<Card*> Deck::getDeckVec() const {

	this->toString();
	vector<Card*> newDeck = this->deck;
	return newDeck;
}

void Deck::copy(const Deck& otherDeck) {

	vector<Card*> copiedDeck;
	this->deck = copiedDeck;
	Card* tempCard;
	otherDeck.getDeckVec().begin();
	otherDeck.getDeckVec().end();
	cout << "vec empty? " << otherDeck.getDeckVec().empty() << endl;
	cout << "vec siZe: " << otherDeck.getDeckVec().size() << endl;

	for(vector<Card*>::iterator it = otherDeck.getDeckVec().begin() ; it != otherDeck.getDeckVec().end(); it++){
		cout << "it " << *it << endl;
		// cout << "*it: " << (*it)->toString() << endl;
		cout << "after toString" << endl;
		if((*it)->isFigure()){

			tempCard = new FigureCard(**it);
		}
		else {

			tempCard = new NumericCard(**it);
		}

		this->deck.push_back(tempCard);
	}
}

Deck& Deck::operator=(Deck& otherDeck) {

	cout << "hello" << endl;
	if(this != &otherDeck) {
		this->copy(otherDeck);
	}

	return *this;
}