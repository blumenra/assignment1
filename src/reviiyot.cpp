#include <iostream>

#include <Game.h>


#include <Card.h>
#include <Deck.h>
#include <Hand.h>

using namespace std;

void printIntVector(vector<int> vec);
void printCardVector(vector<Card*>& vec);
void cardTest();
void deckTest();
void handTest();

int main(int argc, char **argv) {



	// cardTest();
	// deckTest();
	handTest();

	cout << "Exiting main" << endl;













// ORIGINAL TEXT- DO NOT TOUCH!!!-------------------------------------------------
	
	// char* configurationFile = argv[1];

	// Game game = Game(configurationFile);
	// game.init();
 // 	Game initializedGame = game;
 // 	game.play();  

	// cout << std::endl;
 // 	game.printWinner();
	// game.printNumberOfTurns();
	// cout << "----------" << endl;
	// cout<<"Initial State:"<<endl;
 //  	initializedGame.printState();
	// cout<<"----------"<<endl;
	// cout<<"Final State:"<<endl;
	// game.printState();

// ORIGINAL TEXT- DO NOT TOUCH!!!-------------------------------------------------

	return 0;
}


void cardTest() {

	cout << "start main:" << endl;

	cout << "creating new shape of Heart.." << endl;
	Shape shape(Heart);

	cout << "creating new figure of Ace.." << endl;
	Figure figure(Ace);

	cout << "creating new figureCard.." << endl;
	Card* figuredCard = new FigureCard(shape, figure);

	cout << "toString of card (figured): " << figuredCard->toString() + "\n" << endl;

	cout << "getFigure: " << figuredCard->getStrValue() + "\n" << endl;


	cout << "creating new numericCard.." << endl;
	Card* numericCard = new NumericCard(shape, 1234);

	cout << "toString of card (numeric): " << numericCard->toString() + "\n" << endl;

	cout << "getStrNumber of numericCard:" << numericCard->getStrValue() + "\n" << endl;



	cout << "Exiting cardTest!" << endl;

}

void deckTest() {

	Shape shape(Heart);

	cout << "creating new figure of King.." << endl;
	Figure figure(King);

	cout << "creating new figureCard.." << endl;
	Card* figuredCard = new FigureCard(shape, figure);

	cout << "creating new numericCard.." << endl;
	Card* numericCard = new NumericCard(shape, 1234);

	vector<Card*> cards;
	cout << "Is this cards empty?: " << cards.empty() << endl;

	cards.push_back(figuredCard);
	cards.push_back(numericCard);

	// cards.pop_back();


	Deck deck(cards);

	cout << "Is this deck empty?: " << deck.isEmpty() << endl;

	cout << "The deck's size?: " << deck.getNumberOfCards() << endl;

	cout << "Deck: " << deck.toString() << endl;

	// cout << "toString of fetched card: " << deck.fetchCard()->toString() + "\n" << endl;

	cout << "Is this deck empty?: " << deck.isEmpty() << endl;

	cout << "The deck's size?: " << deck.getNumberOfCards() << endl;

	cout << "Deck: " << deck.toString() << endl;

	vector<Card*> cards2;

	cards2 = deck.giveCards(1);

	Deck deck2(cards2);

	cout << "Is this deck2 empty?: " << deck2.isEmpty() << endl;

	cout << "The deck2's size?: " << deck2.getNumberOfCards() << endl;

	cout << "Deck2: " << deck2.toString() << endl;

	// cout << "toString of fetched card: " << deck.fetchCard()->toString() + "\n" << endl;

	cout << "Is this deck2 empty?: " << deck2.isEmpty() << endl;

	cout << "The deck2's size?: " << deck2.getNumberOfCards() << endl;

	cout << "Deck2: " << deck2.toString() << endl;

	cout << "Is this deck empty?: " << deck.isEmpty() << endl;

	cout << "The deck's size?: " << deck.getNumberOfCards() << endl;

	cout << "Deck: " << deck.toString() << endl;



	cout << "Exiting deckTest!" << endl;

}

void handTest() {

	Shape shapeC(Club);
	Shape shapeD(Diamond);
	Shape shapeH(Heart);
	Shape shapeS(Spade);

	Figure figureJ(Jack);
	Figure figureQ(Queen);
	Figure figureK(King);
	Figure figureA(Ace);

	// CARDS CREATIONS ---------
	cout << "Creating figure cards" << endl;
	Card* figuredCard3 = new FigureCard(shapeC, figureK);
	Card* figuredCard4 = new FigureCard(shapeD, figureA);
	Card* figuredCard2 = new FigureCard(shapeS, figureQ);
	Card* figuredCard1 = new FigureCard(shapeC, figureJ);

	cout << "Creating numeirc cards" << endl;
	Card* numericCard1 = new NumericCard(shapeC, 2);
	Card* numericCard3 = new NumericCard(shapeH, 11);
	Card* numericCard2 = new NumericCard(shapeS, 2);

	// CARDS CREATIONS ---------

	vector<Card*> figureCards;
	vector<Card*> numericCards;

	figureCards.push_back(figuredCard1);
	figureCards.push_back(figuredCard2);
	figureCards.push_back(figuredCard3);
	figureCards.push_back(figuredCard4);

	numericCards.push_back(numericCard1);
	numericCards.push_back(numericCard2);
	numericCards.push_back(numericCard3);

	cout << "creating a hand with the above cards.." << endl;

	Hand hand(figureCards, numericCards);


	//toString
	cout << "hand toString result: " << hand.toString() << endl;

	//getNumberOfCards
	cout << "hand getNumberOfCards result: " << hand.getNumberOfCards() << endl;

	//isEmpty
	vector<Card*> figureCardsVec1;
	vector<Card*> numericCardsVec2;

	Hand hand2(figureCardsVec1, numericCardsVec2);

	cout << "hand1 isEmpty result: " << hand2.isEmpty() << endl;

	//findCardsByValue

	figureCards.pop_back();
	Card* figuredCardH = new FigureCard(shapeH, figureK);
	Card* figuredCardK2 = new FigureCard(shapeD, figureK);
	Card* figuredCardKS = new FigureCard(shapeS, figureK);
	figureCards.push_back(figuredCardK2);
	figureCards.push_back(figuredCardH);
	figureCards.erase(figureCards.begin());
	Hand hand3(figureCards, numericCards);
	
	cout << "\n" << "Hand3: " << hand3.toString() << endl;
	Card* figuredCardJ = new FigureCard(shapeS, figureJ);
	Card* figuredCardQ = new FigureCard(shapeD, figureQ);
	Card* figuredCardA = new FigureCard(shapeC, figureA);




	Card* numericCard22 = new NumericCard(shapeH, 2);
	Card* numericCard212 = new NumericCard(shapeH, 12);
	Card* numericCard28 = new NumericCard(shapeH, 8);
	Card* numericCard11b = new NumericCard(shapeS, 11);

	// cout << "hand findCardsByValue vector content: ";
	// printIntVector(hand3.findCardsByValue(*figuredCardJ));
	// cout << "hand findCardsByValue vector content: ";
	// printIntVector(hand3.findCardsByValue(*figuredCardQ));
	// cout << "hand findCardsByValue vector content: ";
	// printIntVector(hand3.findCardsByValue(*figuredCardA));

	cout << "hand findCardsByValue vector content: ";
	printIntVector(hand3.findCardsByValue(*figuredCardKS));


	//findCardsByShape

	cout << "hand findCardsByShape index value: " << hand3.findPlaceByShape(*figuredCardKS, 0, 1, 2) << endl;


	cout << "Exiting handTest!" << endl;


	//howManyOfValue

	//cout << "howManyOfValue, this many:  " << hand3.howManyOfValue(*numericCard22) << endl;


	//isPlaceInsideVector

	cout << "isPlaceInsideVector (1, 0) : " << hand3.isPlaceInsideVector(1, 0) << endl;
	cout << "isPlaceInsideVector (1, 3) : " << hand3.isPlaceInsideVector(1, 3) << endl;
	cout << "isPlaceInsideVector (0, 1) : " << hand3.isPlaceInsideVector(0, 1) << endl;
	cout << "isPlaceInsideVector (0, 10) : " << hand3.isPlaceInsideVector(0, 10) << endl;
	//cout << "isPlaceInsideVector (1, -1) : " << hand3.isPlaceInsideVector(2, 1) << endl;


	// findCardPlace
	cout << "findCardPlace: " << endl;
	printIntVector(hand3.findCardPlace(*figuredCardKS));


	//addCard
	cout << "addCard: " << hand3.addCard(*figuredCardKS) << endl;
	cout << "\n" << "Hand3: " << hand3.toString() << endl;
	cout << "addCard: " << hand3.addCard(*figuredCardKS) << endl;
	cout << "\n" << "Hand3: " << hand3.toString() << endl;
	cout << "addCard: " << hand3.addCard(*numericCard28) << endl;
	cout << "\n" << "Hand3: " << hand3.toString() << endl;
	cout << "addCard: " << hand3.addCard(*numericCard11b) << endl;
	cout << "\n" << "Hand3: " << hand3.toString() << endl;
	cout << "addCard: " << hand3.addCard(*numericCard22) << endl;
	cout << "\n" << "Hand3: " << hand3.toString() << endl;


	//receiveCards
	vector<Card*> figureCardsN;

	figureCardsN.push_back(figuredCard1);
	//figureCardsN.push_back(figuredCard3);
	figureCardsN.push_back(figuredCard4);

	figureCardsN.push_back(numericCard212);
	Card* numericCard11d = new NumericCard(shapeD, 11);
	Card* numericCard11c = new NumericCard(shapeC, 11);
	Card* numericCard2d = new NumericCard(shapeD, 2);
	Card* numericCard55d = new NumericCard(shapeD, 55);

	figureCardsN.push_back(numericCard11d);
	figureCardsN.push_back(numericCard11c);

	cout << "receiveCards: " << endl;
	cout << "\n" << "Hand3: " << hand3.toString() << endl;
	cout << "\n" << "received: "<< endl;
	printCardVector(figureCardsN);

	hand3.receiveCards(figureCardsN);
	cout << "\n" << "Hand3: " << hand3.toString() << endl;	

	// cout << "\n" << "received: "<< endl;
	// printCardVector(figureCardsN);


	//giveCardsOfValue
	vector<Card*> givenCards;
	cout << "\n" << "Hand3: " << hand3.toString() << endl;
	cout << "Asked \" Do you have any 2s? \" " << endl;
	givenCards = hand3.giveCardsOfValue(*numericCard2d);
	printCardVector(givenCards);
	cout << "\n" << "Hand3: " << hand3.toString() << endl;

	cout << "Asked \" Do you have any 55s? \" " << endl;
	givenCards = hand3.giveCardsOfValue(*numericCard55d);
	printCardVector(givenCards);
	cout << "\n" << "Hand3: " << hand3.toString() << endl;


	//removeCard
	cout << "\n" << "Hand3: " << hand3.toString() << endl;
	cout << "was the card found and deleted? " << hand3.removeCard(*numericCard28) << endl;
	cout << "\n" << "Hand3: " << hand3.toString() << endl;
}

void printIntVector(vector<int> vec) {
	for(vector<int>::iterator it = vec.begin() ; it != vec.end(); it++){
		cout << to_string(*it) + " ";
	}
	cout << endl;
}

void printCardVector(vector<Card*>& vec) {
	for(vector<Card*>::iterator it = vec.begin() ; it != vec.end(); it++){
		cout << (*it)->toString() + " ";
	}
	cout << endl;
}