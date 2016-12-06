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

	// cout << endl;
	// cout << "player:" << toString() << endl;
	// cout << "couner: " << counter << endl;
	// cout << "minFound: " << minFound << endl;
	// cout << "it: " << (*it)->toString() << endl;
	// cout << "tempCard: " << tempCard->toString() << endl;
	// cout << "chosenCard: " << chosenCard->toString() << endl;
	// cout << endl;


	if(!figureHand.empty()) {

		tempCard = figureHand.back();
		chosenCard = figureHand.back();
		
		for(vector<Card*>::reverse_iterator rit = figureHand.rbegin()+1 ; rit != figureHand.rend(); rit++){
			if(compareFigures(tempCard->getStrValue(), (*rit)->getStrValue()) == 0) {
				counter++;
			}
			else if(compareFigures(tempCard->getStrValue(), (*rit)->getStrValue()) > 0) {
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


/****PlayerType2****/

PlayerType2::PlayerType2(string name, int position)
: Player(name, position)
{}

Card* PlayerType2::chooseCardToRequest() {
	
	if(this->didIwin()){
		throw invalid_argument("Cannot choose card from empty hand!!!");
	}

	Card* chosenCard;
	Card* tempCard;
	vector<Card*> figureHand = getFigureHand();
	vector<Card*> numericHand = getNumericHand();


	int counter = 1;
	int minFound = 4;

	if(!numericHand.empty()) {
		
		tempCard = numericHand.front();
		chosenCard = numericHand.front();

		for(vector<Card*>::iterator it = numericHand.begin()+1 ; it != numericHand.end(); it++){

			if(compareNumbers(tempCard->getStrValue(), (*it)->getStrValue()) == 0) {
				counter++;
				// if there are 3 cards of each previous value and there are 2 last cards of the same value
				if((it == numericHand.end()-1) && (counter < minFound)) {
					chosenCard = tempCard;
					minFound = counter;
				}
			}
			else if(compareNumbers(tempCard->getStrValue(), (*it)->getStrValue()) < 0) {
				
				if(counter < minFound) {
					chosenCard = tempCard;
					minFound = counter;
				}
				
				tempCard = (*it);
				// if all the previous values have more than one card and the last value has one
				if(it == numericHand.end()-1 && minFound != 1) {
					chosenCard = tempCard;
					minFound = 1;
				}

				counter = 1;
			}
			else {
				throw invalid_argument("numericHand is out of order!!!");
			}
		}
	}
	else {
		if(!figureHand.empty()) {
			chosenCard = figureHand.front();
		}
	}

	counter = 1;

	if(!figureHand.empty()) {

		tempCard = figureHand.front();
		
		for(vector<Card*>::iterator it = figureHand.begin()+1 ; it != figureHand.end(); it++){
			if(compareFigures(tempCard->getStrValue(), (*it)->getStrValue()) == 0) {
				counter++;
				if((it == figureHand.end()-1) && (counter < minFound)) {
					chosenCard = tempCard;
					minFound = counter;
				}
			}
			else if(compareFigures(tempCard->getStrValue(), (*it)->getStrValue()) < 0) {


				if(counter < minFound) {
					chosenCard = tempCard;
					minFound = counter;
				}
				
				tempCard = (*it);

				if(it == figureHand.end()-1 && minFound != 1) {
					chosenCard = tempCard;
					minFound = 1;
				}
				
				counter = 1;

			}
			else {
				throw invalid_argument("FigureHand is out of order!!!");
			}

		}
	}

	return chosenCard;
}

Player* PlayerType2::choosePlayer(vector<Player*> players){

	return choosePlayerWithMostCards(players);
}