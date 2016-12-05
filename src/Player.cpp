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

Player::~Player() {
	delete this->chosenPlayer;
	delete this->chosenCard;
}

string Player::toString() {
	
	string s = name + ": ";
	s += this->Hand::toString();

	return s;
}

bool Player::didIwin() {
	return this->isEmpty();
}