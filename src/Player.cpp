 #include <Player.h>

void Player::fetchFromDeck(Deck deck, int amountToFetch){
	
	vector<Card*> given = deck.giveCards(amountToFetch);
	receiveCards(given);
}

