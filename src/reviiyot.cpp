#include <iostream>

// #include <Game.h>


#include "../include/Card.h"
#include "../include/Deck.h"

using namespace std;

int main(int argc, char **argv) {

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

cards2 = deck.giveCards(-1);

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

//CARD TEST START----------------------------

// cout << "start main:" << endl;

// cout << "creating new shape of Heart.." << endl;
// Shape shape(Heart);

// cout << "creating new figure of Ace.." << endl;
// Figure figure(Ace);

// cout << "creating new figureCard.." << endl;
// Card* figuredCard = new FigureCard(shape, figure);

// cout << "toString of card: " << figuredCard->toString() + "\n" << endl;

// cout << "getFigure: " << figuredCard->getStrValue() + "\n" << endl;



// cout << "creating new numericCard.." << endl;
// Card* numericCard = new NumericCard(shape, 1234);

// cout << "toString of card: " << numericCard->toString() + "\n" << endl;

// cout << "getStrNumber of numericCard:" << numericCard->getStrValue() + "\n" << endl;

//CARD TEST END--------------------------


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
	cout << "Exiting main" << endl;
	return 0;
}

