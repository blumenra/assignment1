#include <iostream>
#include <sstream>

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
void playerTest();

// These are for Game**************************************************************************
vector<Card*> cardsForDeckCreator(string parsedDeck);
Shape stringToShape(string strShape);
Figure stringToFigure(string strFigure);
bool isFigure(string value);
// These are for Game**************************************************************************

int main(int argc, char **argv) {



	// cardTest();
	//deckTest();
	// handTest();
	playerTest();

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

	cards.push_back(new FigureCard(shape, figure));
	cards.push_back(new NumericCard(shape, 1234));

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

	vector<Card*> figureCards1;
	vector<Card*> numericCards1;

	figureCards.push_back(figuredCard1);
	figureCards.push_back(figuredCard2);
	figureCards.push_back(figuredCard3);
	figureCards.push_back(figuredCard4);

	numericCards.push_back(numericCard1);
	numericCards.push_back(numericCard2);
	numericCards.push_back(numericCard3);

	cout << "creating a hand with the above cards.." << endl;

	Hand hand;
	hand.receiveCards(figureCards1);
	hand.receiveCards(numericCards1);



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

void playerTest() {
	string parsedDeck("12C QH JS 13D KC 3H 3D 9D 14C KS AD JD 8D 4D 7C 2S 11H 10D 15S 11D QD 2C 6D 15D 13S 5S 8C 13C 3S 2D 12H JC 4H 3C 15C 15H 11S 7D 10C QS 11C 6C 8H 5H 9C 4C 5C KH 13H 14S QC 12D 10H 14H 6S 5D 10S KD 7H AH 7S 9S JH 2H 4S 9H AS 6H AC 8S 12S 14D");
	
	vector<Card*> cards = cardsForDeckCreator(parsedDeck);
	Deck* deck = new Deck(cards);
	cout << "initial deck: " << "\n" << deck->toString() << endl;
	cout << endl;

	// players creations
	Player* player1 = new Player("Alon", 0);
	Player* player2 = new Player("Ofer", 1);
	Player* player3 = new Player("Rick", 2);
	Player* player4 = new Player("Morty", 3);




	// getName
	cout << "Player1's name: " << player1->getName() << endl;
	cout << "Player2's name: " << player2->getName() << endl;
	cout << "Player3's name: " << player3->getName() << endl;
	cout << "Player4's name: " << player4->getName() << endl;
	cout << endl;

	//getPosition
	cout << "Player1's position: " << player1->getPosition() << endl;
	cout << "Player2's position: " << player2->getPosition() << endl;
	cout << "Player3's position: " << player3->getPosition() << endl;
	cout << "Player4's position: " << player4->getPosition() << endl;
	cout << endl;

	//fetchFromDeck
	player1->fetchFromDeck(*deck, 7);
	player2->fetchFromDeck(*deck, 7);
	player3->fetchFromDeck(*deck, 7);
	player4->fetchFromDeck(*deck, 7);

	cout << "Deck after fetches: " << "\n" << deck->toString() + "\n" << endl;
	cout << endl;

	cout << "Player1's hand: " << player1->toString() << endl;
	cout << "Player2's hand: " << player2->toString() << endl;
	cout << "Player3's hand: " << player3->toString() << endl;
	cout << "Player4's hand: " << player4->toString() << endl;
	cout << endl;

}


// These are for Game**************************************************************************
vector<Card*> cardsForDeckCreator(string parsedDeck) {

	stringstream parsedDeckss(parsedDeck);

	vector<Card*> cards;
	
	vector<string> strCards;
	while(parsedDeckss.good()){
		string substr;
		getline(parsedDeckss, substr, ' ');
		strCards.push_back( substr );
	}

	for(vector<string>::iterator it = strCards.begin() ; it != strCards.end(); it++){
		// cout << "input string: " << *it << endl;
		int itLength = (*it).length();
		string strValue = (*it).substr(0, itLength -1);
		string strShape = (*it).substr(itLength -1, 1);
		if(isFigure(strValue)){
			cards.push_back(new FigureCard(stringToShape(strShape), stringToFigure(strValue)));
		}
		else{
			cards.push_back(new NumericCard(stringToShape(strShape), stoi(strValue)));
		}
	}

	return cards;
}

Shape stringToShape(string strShape) {
	
	Shape shapeC(Club);
	Shape shapeD (Diamond);
	Shape shapeH(Heart);
	Shape shapeS(Spade);

	if(strShape == "C"){
		return shapeC;
	}
	else if(strShape == "D"){
		return shapeD;
	}
	else if(strShape == "H"){
		return shapeH;
	}
	else if(strShape == "S"){
		return shapeS;
	}
	else{
		throw invalid_argument("The card's shape is invalid!!!");
	}
}

Figure stringToFigure(string strFigure) {
	
	Figure figureJ(Jack);
	Figure figureQ(Queen);
	Figure figureK(King);
	Figure figureA(Ace);

	if(strFigure == "J"){
		return figureJ;
	}
	else if(strFigure == "Q"){
		return figureQ;
	}
	else if(strFigure == "K"){
		return figureK;
	}
	else if(strFigure == "A"){
		return figureA;
	}
	else{
		throw invalid_argument("The card's figure is invalid!!!");
	}
}

bool isFigure(string value){
	bool figure = false;
	if(value == "J" || value == "Q" || value == "K" || value == "A"){
		figure = true;
	}

	return figure;
}

/*
#include <fstream>

ifstream theFile;
theFile.open("/freespace/msc/brukes/Courses/SPL/assignment1/removeMe/configurationFiles/config1.txt");
string line;

while(getline(theFile, line)){

}
*/

// These are for Game**************************************************************************
