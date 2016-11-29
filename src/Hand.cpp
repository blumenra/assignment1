#include "../include/Hand.h"
#include "../include/Card.h"


Hand::Hand(vector<Card*>& figureHand, vector<Card*>& numericHand)
: figureHand(figureHand), numericHand(numericHand)
{}

int Hand::getNumberOfCards() {
	int numOfFigureCards = figureHand.size();
	int numOfNumericCards = numericHand.size();

	return numOfFigureCards + numOfNumericCards;
}

string Hand::toString() {

	string strHand;

	for(vector<Card*>::iterator it = numericHand.begin() ; it != numericHand.end(); it++){
		strHand += (*it)->toString() + " ";
	}

	for(vector<Card*>::iterator it = figureHand.begin() ; it != figureHand.end(); it++){
		strHand += (*it)->toString() + " ";
	}

	int strHandLength = strHand.length();
	string strHandNoLastSpace = strHand.substr(0, strHandLength-1);
	return strHandNoLastSpace;

}

bool Hand::isEmpty() {
	
	return getNumberOfCards() == 0;
}

vector<int> Hand::findCardsByValue(Card& card) {

	return card.valuateMe(*this);
}