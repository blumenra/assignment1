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
	
	cout << "Deck before: " << deck.toString() + "\n" << endl;
	vector<Card*> given = deck.giveCards(amountToFetch);
	receiveCards(given);
	cout << "Deck after: " << deck.toString() + "\n" << endl;

}

