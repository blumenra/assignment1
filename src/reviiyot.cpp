#include <iostream>

// #include <Game.h>


#include "../include/Card.h"
// #include <Card.h>

using namespace std;

int main(int argc, char **argv) {

cout << "start main:" << endl;

cout << "creating new shape of Heart.." << endl;
Shape shape(Heart);

cout << "creating new figure of Ace.." << endl;
Figure figure(Ace);

cout << "creating new figureCard.." << endl;
Card* figuredCard = new FigureCard(shape, figure);

cout << "toString of card: " << figuredCard->toString() + "\n" << endl;

cout << "getFigure: " << figuredCard->getStrValue() + "\n" << endl;



cout << "creating new numericCard.." << endl;
Card* numericCard = new NumericCard(shape, 1234);

cout << "toString of card: " << numericCard->toString() + "\n" << endl;

cout << "getStrNumber of numericCard:" << numericCard->getStrValue() + "\n" << endl;

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

