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

int Hand::convertFigureToIndex(string figure) {

	if(figure == "J") {
		return 1;
	}
	else if(figure == "Q") {
		return 2;
	}
	else if(figure == "K") {
		return 3;
	}
	else if(figure == "A") {
		return 4;
	}
	else {
		throw invalid_argument("The figure is invalid!!!");
	}

}

int Hand::convertNumberToIndex(string number) {
	
	return stoi(number);
}

int Hand::convertShapeToIndex(Shape shape) {
	switch(shape) {
		case Club:
			return 1;
		case Diamond:
			return 2;
		case Heart:
			return 3;
		case Spade:
			return 4;
		default:
			throw invalid_argument("The shape is invalid!!!");
	}
}

int Hand::compareShapes(Shape receivedShape, Shape inHandShape) {
	
	return convertShapeToIndex(receivedShape) - convertShapeToIndex(inHandShape);
}

int Hand::compareFigures(string receivedFigure, string inHandFigure) {

	return convertFigureToIndex(receivedFigure) - convertFigureToIndex(inHandFigure);
}

int Hand::compareNumbers(string receivedNumber, string inHandNumber) {
	
	return convertNumberToIndex(receivedNumber) - convertNumberToIndex(inHandNumber);
}

vector<int> Hand::findCardsByValue(Card& card) {

	return card.valuateMe(*this);
}

vector<int> Hand::findCardsByValue(FigureCard& card) {
	
	cout << numericHand.size() << endl;
	vector<int> valuePlacements;
	valuePlacements.push_back(0); // figureHand is the value 0

	for(unsigned int i = 0; i < figureHand.size(); i++){
		if((compareFigures(card.getStrValue(), figureHand[i]->getStrValue())) == 0) {
			valuePlacements.push_back(i);
			int lastIndex = i;
			for(unsigned int j = i+1; j < figureHand.size(); j++) {
				if((compareFigures(card.getStrValue(), figureHand[j]->getStrValue())) == 0 ) {
					lastIndex = j;
				}
				else {
					break;
				}
			}
			valuePlacements.push_back(lastIndex);
			return valuePlacements;
		}
		else if((compareFigures(card.getStrValue(), figureHand[i]->getStrValue())) < 0) {
			valuePlacements.push_back(i);
			valuePlacements.push_back(-1);
			return valuePlacements;
		}
	}

	valuePlacements.push_back(figureHand.size());
	valuePlacements.push_back(-1); // -1 means didnt find a card of the same value
	return valuePlacements;
}

vector<int> Hand::findCardsByValue(NumericCard& card) {
	vector<int> valuePlacements;
	valuePlacements.push_back(1); // numericHand is the value 1
	cout << numericHand.size() << endl;

	for(unsigned int i = 0; i < numericHand.size(); i++){
		if((compareNumbers(card.getStrValue(), numericHand[i]->getStrValue())) == 0) {
			valuePlacements.push_back(i);
			int lastIndex = i;
			for(unsigned int j = i+1; j < numericHand.size(); j++) {
				if((compareNumbers(card.getStrValue(), numericHand[j]->getStrValue())) == 0 ) {
					lastIndex = j;
				}
				else {
					break;
				}
			}
			valuePlacements.push_back(lastIndex);
			return valuePlacements;
		}
		else if((compareNumbers(card.getStrValue(), numericHand[i]->getStrValue())) < 0) {
			valuePlacements.push_back(i);
			valuePlacements.push_back(-1);
			return valuePlacements;
		}
	}

	valuePlacements.push_back(numericHand.size());
	valuePlacements.push_back(-1); // -1 means didnt find a card of the same value
	return valuePlacements;
}

int Hand::findPlaceByShape(Card& card, int vec, int begin, int end) {
	int shapePlacement;
	vector<Card*> subHand;

	switch(vec) {
		case 0:
			subHand = figureHand;
			break;
		case 1:
			subHand = numericHand;
			break;
		default:
			throw invalid_argument("The sub-hand is invalid!!!");
	}


	for(int i = begin; i <= end; i++){
		if((compareShapes(card.getShape(), subHand[i]->getShape())) == 0) {
			throw invalid_argument("Two identicle CARDS where found!!!");		
		}
		else if((compareShapes(card.getShape(), subHand[i]->getShape())) < 0) {
			cout << "card: " << card.toString() << endl;
			cout << "getShape: " << subHand[i]->toString() << endl;
			shapePlacement = i;
			return shapePlacement;
		}
	}

	shapePlacement = end + 1;

	return shapePlacement;
}