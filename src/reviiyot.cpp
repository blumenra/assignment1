#include <iostream>

// #include <Game.h>


#include "../include/Card.h"
#include "../include/Deck.h"
#include "../include/Hand.h"

using namespace std;

void printIntVector(vector<int> vec);
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
	Card* figuredCard3 = new FigureCard(shapeS, figureK);
	Card* figuredCard4 = new FigureCard(shapeD, figureA);
	Card* figuredCard2 = new FigureCard(shapeS, figureQ);
	Card* figuredCard1 = new FigureCard(shapeC, figureJ);

	cout << "Creating numeirc cards" << endl;
	Card* numericCard1 = new NumericCard(shapeC, 2);
	Card* numericCard2 = new NumericCard(shapeH, 11);
	// CARDS CREATIONS ---------

	vector<Card*> figureCards;
	vector<Card*> numericCards;

	figureCards.push_back(figuredCard1);
	figureCards.push_back(figuredCard2);
	figureCards.push_back(figuredCard3);
	figureCards.push_back(figuredCard4);

	numericCards.push_back(numericCard1);
	numericCards.push_back(numericCard2);

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
	Card* figuredCardK = new FigureCard(shapeC, figureK);
	figureCards.push_back(figuredCardK);
	figureCards.erase(figureCards.begin());
	Hand hand3(figureCards, numericCards);
	
	cout << "\n" + hand3.toString() << endl;
	Card* figuredCardJ = new FigureCard(shapeS, figureJ);
	Card* figuredCardQ = new FigureCard(shapeD, figureQ);
	Card* figuredCardK2 = new FigureCard(shapeD, figureK);
	Card* figuredCardA = new FigureCard(shapeC, figureA);


	cout << "hand findCardsByValue vector content: ";
	printIntVector(hand3.findCardsByValue(*figuredCardJ));
	// cout << "hand findCardsByValue vector content: ";
	// printIntVector(hand3.findCardsByValue(*figuredCardQ));
	// cout << "hand findCardsByValue vector content: ";
	// printIntVector(hand3.findCardsByValue(*figuredCardK2));

	cout << "hand findCardsByValue vector content: ";
	printIntVector(hand3.findCardsByValue(*figuredCardA));



	cout << "Exiting handTest!" << endl;
}

void printIntVector(vector<int> vec) {
	for(vector<int>::iterator it = vec.begin() ; it != vec.end(); it++){
		cout << to_string(*it) + " ";
	}
	cout << endl;
}