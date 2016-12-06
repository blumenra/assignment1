 #include <Player.h>

Player::Player(string name, int position)
: Hand(), name(name), position(position)
{}

string Player::getName() const {
	return name;
}

int Player::getPosition() const {
	return position;
}

void Player::fetchFromDeck(Deck& deck, int amountToFetch){
	
	vector<Card*> given = deck.giveCards(amountToFetch);
	receiveCards(given);
}

Player::~Player()
{}

string Player::toString() {
	
	string s = name + ": ";
	s += this->Hand::toString();

	return s;
}

bool Player::didIwin() {

	return this->isEmpty();
}

Player* Player::choosePlayerWithMostCards(vector<Player*> players){
	
	int maxCards = 0;
	int counter = 0;
	Player* chosenPlayer = players.front();

	for(vector<Player*>::reverse_iterator rit = players.rbegin() ; rit != players.rend(); rit++){
		counter = (*rit)->getNumberOfCards();

		if(counter > maxCards && (*rit)->getPosition() != this->position){
			chosenPlayer = *rit;
			maxCards = counter;
		}
	}

	return chosenPlayer;
}


/****PlayerType1****/

PlayerType1::PlayerType1(string name, int position)
: Player(name, position)
{}

Card* PlayerType1::chooseCardToRequest() {
	
	if(this->didIwin()){
		throw invalid_argument("Cannot choose card from empty hand!!!");
	}

	Card* chosenCard;
	Card* tempCard;
	vector<Card*> figureHand = getFigureHand();
	vector<Card*> numericHand = getNumericHand();


	int counter = 1;
	int maxFound = 1;

	if(!figureHand.empty()) {

		tempCard = figureHand.back();
		chosenCard = figureHand.back();
		
		for(vector<Card*>::reverse_iterator rit = figureHand.rbegin()+1 ; rit != figureHand.rend(); rit++){
			// cout << "tempCard: " << tempCard->toString() << endl;
			// cout << "rit: " << (*rit)->toString() << endl;
			// cout << "chosenCard: " << chosenCard->toString() << endl;
			// cout << endl;
			if(compareFigures(tempCard->getStrValue(), (*rit)->getStrValue()) == 0) {
				counter++;
			}
			else if(compareFigures(tempCard->getStrValue(), (*rit)->getStrValue()) > 0) {
				// cout << "inside elseif- tempCard: " << tempCard->toString() << endl;
				// cout << "inside elseif- chosenCard: " << chosenCard->toString() << endl;
				tempCard = (*rit);
				counter = 1;
			}
			else {
				throw invalid_argument("FigureHand is out of order!!!");
			}

			if(counter > maxFound) {
				chosenCard = tempCard;
				maxFound = counter;
			}
		}
	}
	else {
		if(!numericHand.empty()) {
			chosenCard = numericHand.back();
		}
	}

	counter = 1;

	if(!numericHand.empty()) {
		
		tempCard = numericHand.back();
		
		for(vector<Card*>::reverse_iterator rit = numericHand.rbegin()+1 ; rit != numericHand.rend(); rit++){
			if(compareNumbers(tempCard->getStrValue(), (*rit)->getStrValue()) == 0) {
				counter++;
			}
			else if(compareNumbers(tempCard->getStrValue(), (*rit)->getStrValue()) > 0) {
				tempCard = (*rit);
				counter = 1;
			}
			else {
				throw invalid_argument("numericHand is out of order!!!");
			}

			if(counter > maxFound) {
				chosenCard = tempCard;
				maxFound = counter;
			}
		}
	}

	return chosenCard;
}

Player* PlayerType1::choosePlayer(vector<Player*> players){

	return choosePlayerWithMostCards(players);
}
