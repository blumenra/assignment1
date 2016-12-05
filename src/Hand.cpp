#include <Hand.h>
#include <Card.h>

Hand::Hand() {}

// CONSTRACTOR FOR DEBUGGING ONLY (can be removed later..)
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

	// vec[0] = the vector that the value is in. 0- figureHand, 1- NumericHand
	// vec[1] = the first index containg the value. If the value isn't found this is the index where the card should be inserted.
	// vec[2] = the last index containg the value. If the value isn't found it is -1.

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

	// vec[0] = the vector that the value is in. 0- figureHand, 1- NumericHand
	// vec[1] = the first index containg the value. If the value isn't found this is the index where the card should be inserted.
	// vec[2] = the last index containg the value. If the value isn't found it is -1.

	vector<int> valuePlacements;
	valuePlacements.push_back(1); // numericHand is the value 1

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
	
	if(begin > end){
		throw invalid_argument("The end is smaller than the begin!!!");
	}

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
			//this is where the shapes are identicle and is used for removeCard
			shapePlacement = i;
			return shapePlacement;		
		}
		else if((compareShapes(card.getShape(), subHand[i]->getShape())) < 0) {
			shapePlacement = i;
			return shapePlacement;
		}
	}

	shapePlacement = end + 1;

	return shapePlacement;
}

bool Hand::isPlaceInsideVector(int vec, int index){
	
	int vecLength = -1;

	if (index >= 0){
		if(vec == 0){
			vecLength = figureHand.size();
		}
		else if(vec == 1){
			vecLength = numericHand.size();

		}
		else{
			throw invalid_argument("The vector int is invalid!!!");
		}
	}
	else{
		throw invalid_argument("The index is invalid!!!");
	}

	return (index < vecLength);
}

vector<int> Hand::findCardPlace(Card& card){

	// vec[0] = the vector that the value is in. 0- figureHand, 1- NumericHand
	// vec[1] = the first index containg the value. If the value isn't found this is the index where the card should be inserted.
	// vec[2] = the last index containg the value. If the value isn't found it is -1.
	// vec[3] = the index where the card should be inserted.

	vector<int> place;
	vector<int> placeByValue = findCardsByValue(card);
	place.push_back(placeByValue[0]);
	place.push_back(placeByValue[1]);
	place.push_back(placeByValue[2]);

	if(placeByValue[2] == -1){
		place.push_back(placeByValue[1]);

	}
	else {
		int index = findPlaceByShape(card, placeByValue[0], placeByValue[1], placeByValue[2]);
		place.push_back(index);
	}

	return place;
}

bool Hand::addCard(Card &card){

	vector<int> place = findCardPlace(card);
	//This if checks if we completed a foursome
	if(place[2]-place[1] == 2){

		if(place[0] == 0){
			deleteCards(figureHand, place[1], place[2]);
		}
		else if(place[0] == 1){
			deleteCards(numericHand, place[1], place[2]);
		}
		else{
			throw invalid_argument("The vector int is invalid!!!");
		}
		return false;
	}
	else{
		if(place[0] == 0){
			insertCard(figureHand, card, place[0], place[3]);
		}
		else if(place[0] == 1){
			insertCard(numericHand, card, place[0], place[3]);
		}
		else{
			throw invalid_argument("The vector int is invalid!!!");
		}
		return true;
	}
}

void Hand::deleteCards(vector<Card*>& subHand, int begin, int end){

	for(int i=begin; i<= end; i++){
		Card* tempCard = subHand[begin];
		subHand.erase(subHand.begin() + begin);
		delete tempCard;
	}
}

void Hand::insertCard(vector<Card*>& subHand, Card &card, int vec, int place){

	if(isPlaceInsideVector(vec, place)){
		subHand.insert(subHand.begin() + place, &card);
	}
	else{
		subHand.push_back(&card);
	}
}

void Hand::receiveCards(vector<Card*>& cards){

	for(vector<Card*>::iterator it = cards.begin() ; it != cards.end(); it++){
		if(!addCard(**it)){
			delete *it;
		}
	}
}

vector<Card*> Hand::giveCardsOfValue(Card& card){

	vector<Card*> cardsToGive;
	vector<int> cardplaces = findCardsByValue(card);

	if(cardplaces[2] == -1){
		return cardsToGive;
	}
	else{
		if(cardplaces[0] == 0){
			cardsToGive = bundleCardsToGive(figureHand, cardplaces[1], cardplaces[2]);
		}
		else if(cardplaces[0] == 1){
			cardsToGive = bundleCardsToGive(numericHand, cardplaces[1], cardplaces[2]);
		}
		else{
			throw invalid_argument("The vector int is invalid!!!");
		}
		return cardsToGive;
	}
}

vector<Card*> Hand::bundleCardsToGive(vector<Card*>& subHand, int begin, int end){

	vector<Card*> cardsToGive;

	for(int i=begin; i<=end; i++){
		cardsToGive.push_back(subHand[begin]);
		subHand.erase(subHand.begin() + begin);
	}

	return cardsToGive;
}

bool Hand::removeCard(Card &card){
	vector<int> place;
	place = findCardPlace(card);
	bool deleted = false;

	if (isPlaceInsideVector(place[0], place[3])){
		if(place[0] == 0){
			if(compareFigures(card.getStrValue(), figureHand[place[3]]->getStrValue()) == 0){
				if(compareShapes(card.getShape(), figureHand[place[3]]->getShape()) == 0){
					deleteCards(figureHand, place[3], place[3]);
					deleted = true;
				}
			}
		}
		else if(place[0] == 1){
			if(compareNumbers(card.getStrValue(), numericHand[place[3]]->getStrValue()) == 0){
				if(compareShapes(card.getShape(), numericHand[place[3]]->getShape()) == 0){
					deleteCards(numericHand, place[3], place[3]);
					deleted = true;
				}
			}
		}
		else{
			throw invalid_argument("The vector int is invalid!!!");
		}
	}

	return deleted;
}

Hand::~Hand(){
	
	//Destroy figureHand
	for(vector<Card*>::iterator it = figureHand.begin() ; it != figureHand.end(); it++){
		delete (*it);
	}

	//Destroy numericHand
	for(vector<Card*>::iterator it = numericHand.begin() ; it != numericHand.end(); it++){
		delete (*it);
	}
}