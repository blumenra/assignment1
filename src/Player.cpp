 #include <Player.h>

Player::Player(string name, int position, int playerType):
Hand(),
name(name),
position(position),
chosenCard(),
chosenCardValue(""),
previouslyChosenPlayerPosition(-1),
chosenPlayerPosition(-1),
playerType(playerType)
{}

Player::Player(Player& otherPlayer):
Hand(),
name(),
position(),
chosenCard(),
chosenCardValue(),
previouslyChosenPlayerPosition(),
chosenPlayerPosition(),
playerType()
{
	
	this->copy(otherPlayer);
}

string Player::getName() const {

	return name;
}

int Player::getPosition() {
	return position;
}

string Player::getChosenCardValue() const {

	return chosenCardValue;
}

void Player::fetchFromDeck(Deck& deck, int amountToFetch) {
	
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

Player* Player::choosePlayerWithMostCards(vector<Player*>& players) {
	
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

	chosenPlayerPosition = chosenPlayer->getPosition();

	return chosenPlayer;
}

Player* Player::choosePlayerCyclicly(vector<Player*>& players, int previouslyChosenPlayerPosition) {
	
	int numberOfPlayers = players.size();
	int chosenPlayerPosition = (previouslyChosenPlayerPosition +1)%numberOfPlayers;
	
	if(chosenPlayerPosition == position){
		chosenPlayerPosition = (chosenPlayerPosition + 1)%numberOfPlayers;
	}

	return players[chosenPlayerPosition];
}

void Player::goTurn(vector<Player *>& players, Deck& deck) {

	chosenCard = this->chooseCardToRequest();
	chosenCardValue = chosenCard->getStrValue();
	Player* chosenPlayer = this->choosePlayer(players);

	vector<Card*> givenCards = chosenPlayer->giveCardsOfValue(*chosenCard);
	if(!givenCards.empty()) {
		this->receiveCards(givenCards);
		chosenPlayer->fetchFromDeck(deck, givenCards.size());
	}
	else {
		this->fetchFromDeck(deck, 1);
	}
}

Card* Player::getChosenCard() {
	
	return chosenCard;
}

int Player::getChosenPlayerPosition() {
	
	return chosenPlayerPosition;
}

int Player::getPreviouslyChosenPlayerPosition() {
	
	return previouslyChosenPlayerPosition;
}

int Player::getPlayerType() {

	return playerType;
}

void Player::copy(Player& otherPlayer) {

	this->name = otherPlayer.getName();
	this->position = otherPlayer.getPosition();
	this->chosenCardValue = getChosenCardValue();
	this->previouslyChosenPlayerPosition = otherPlayer.getPreviouslyChosenPlayerPosition();
	this->chosenPlayerPosition = otherPlayer.getChosenPlayerPosition();
	this->playerType = otherPlayer.getPlayerType();

	Card* tempChosenCard = otherPlayer.getChosenCard();

	vector<Card*> otherFigureHand = otherPlayer.getFigureHand();
	vector<Card*> newFigureHand;
	vector<Card*> otherNumericHand = otherPlayer.getNumericHand();
	vector<Card*> newNumericHand;

	
	for(vector<Card*>::iterator it = otherFigureHand.begin() ; it != otherFigureHand.end(); it++){

		Card* card = new FigureCard(**it);
		newFigureHand.push_back(card);

		if(
			otherPlayer.getChosenPlayerPosition() != -1 &&
			tempChosenCard->isFigure() &&
			Hand::compareShapes(card->getShape(), tempChosenCard->getShape()) == 0 &&
			Hand::compareFigures(card->getStrValue(), tempChosenCard->getStrValue()) == 0
			) {
			
			chosenCard = card;
		}
	}


	for(vector<Card*>::iterator it = otherNumericHand.begin() ; it != otherNumericHand.end(); it++){

		Card* card = new NumericCard(**it);
		newNumericHand.push_back(card);

		if(
			otherPlayer.getChosenPlayerPosition() != -1 &&
			tempChosenCard->isNumeric() &&
			Hand::compareShapes(card->getShape(), tempChosenCard->getShape()) == 0 &&
			Hand::compareNumbers(card->getStrValue(), tempChosenCard->getStrValue()) == 0
			) {

			chosenCard = card;
		}
	}
	
	this->receiveCards(newFigureHand);
	this->receiveCards(newNumericHand);
}

Player& Player::operator=(Player& otherPlayer) {

	if(this != &otherPlayer) {
		this->copy(otherPlayer);
	}

	return *this;
}


/****PlayerType1****/

PlayerType1::PlayerType1(string name, int position)
: Player(name, position, 1)
{}

PlayerType1::PlayerType1(Player& otherPlayerType1):
Player(otherPlayerType1)
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

Player* PlayerType1::choosePlayer(vector<Player*>& players){

	return choosePlayerWithMostCards(players);
}




/****PlayerType2****/

PlayerType2::PlayerType2(string name, int position)
: Player(name, position, 2)
{}

PlayerType2::PlayerType2(Player& otherPlayerType2):
Player(otherPlayerType2)
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
		
		if(numericHand.size() == 1){
			minFound = 1;
		}

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

		if(figureHand.size() == 1){
			minFound = 1;
		}
		
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

Player* PlayerType2::choosePlayer(vector<Player*>& players){

	return choosePlayerWithMostCards(players);
}





/****PlayerType3****/
PlayerType3::PlayerType3(string name, int position)
: Player(name, position, 3)
{}

PlayerType3::PlayerType3(Player& otherPlayerType3):
Player(otherPlayerType3)
{}

Card* PlayerType3::chooseCardToRequest() {
	
	Card* chosenCard;
	vector<Card*> figureHand = getFigureHand();
	vector<Card*> numericHand = getNumericHand();

	if(!figureHand.empty()) {
		chosenCard = figureHand.back();
	}
	else {
		if(!numericHand.empty()) {
			chosenCard = numericHand.back();
		}
		else
			throw invalid_argument("Cannot choose card from empty hand!!!");
	}

	return chosenCard;
}

Player* PlayerType3::choosePlayer(vector<Player*>& players){
	
	Player* chosenPlayer = choosePlayerCyclicly(players, previouslyChosenPlayerPosition);
	previouslyChosenPlayerPosition = chosenPlayer->getPosition();
	chosenPlayerPosition = chosenPlayer->getPosition();

	return chosenPlayer;
}




/****PlayerType4****/
PlayerType4::PlayerType4(string name, int position)
: Player(name, position, 4)
{}

PlayerType4::PlayerType4(Player& otherPlayerType4):
Player(otherPlayerType4)
{}

Card* PlayerType4::chooseCardToRequest() {
	
	Card* chosenCard;
	vector<Card*> figureHand = getFigureHand();
	vector<Card*> numericHand = getNumericHand();

	if(!numericHand.empty()) {
		chosenCard = numericHand.front();
	}
	else {
		if(!figureHand.empty()) {
			chosenCard = figureHand.front();
		}
		else
			throw invalid_argument("Cannot choose card from empty hand!!!");
	}

	return chosenCard;
}

Player* PlayerType4::choosePlayer(vector<Player*>& players){
	
	Player* chosenPlayer = choosePlayerCyclicly(players, previouslyChosenPlayerPosition);
	previouslyChosenPlayerPosition = chosenPlayer->getPosition();
	chosenPlayerPosition = chosenPlayer->getPosition();

	return chosenPlayer;
}


