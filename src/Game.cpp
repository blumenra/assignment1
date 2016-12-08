#include <Game.h>

Game::Game(char* configurationFile) {
	
	this->configFileVec = parseConfigFile(configurationFile);
	this->verbal = stoi(configFileVec[0]);
	this->highestNumericValue = stoi(configFileVec[1]);
	this->turn = 1;

	vector<Player *> players;
	players = playersCreator(configFileVec);
	this->players = players;

	vector<Player*> winners;
	this->winners = winners;

	vector<Card*> cardVec;
	cardVec = deckCreator(configFileVec[2]);
	Deck tempDeck(cardVec);
	this->deck = tempDeck;



	configFileVec.clear();
}

Game::Game(const Game& otherGame){

	this->copy(otherGame);
}

vector<string> Game::parseConfigFile(char* configurationFile) {

	vector<string> configFileVec;
	ifstream file;

	string fileName(configurationFile);
	file.open(configurationFile);

	string line;
	

	while(getline(file, line)){
		if(!line.empty() && (line.at(0) != '#')) {
			configFileVec.push_back(line);
		}
	}

	return configFileVec;
}

vector<Card*> Game::deckCreator(string parsedDeck) {

	stringstream parsedDeckss(parsedDeck);

	vector<Card*> cards;
	
	vector<string> strCards;
	while(parsedDeckss.good()){
		string substr;
		getline(parsedDeckss, substr, ' ');
		if(substr != ""){
			strCards.push_back(substr);
		}
	}

	for(vector<string>::iterator it = strCards.begin() ; it != strCards.end(); it++){
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

Shape Game::stringToShape(string strShape) {
	
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

Figure Game::stringToFigure(string strFigure) {
	
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

bool Game::isFigure(string value){
	bool figure = false;
	if(value == "J" || value == "Q" || value == "K" || value == "A"){
		figure = true;
	}

	return figure;
}

vector<Player *> Game::playersCreator(vector<string> configFileVec){

	vector<Player *> players;
	int position = 0;
	for(vector<string>::iterator it = configFileVec.begin() + 3; it != configFileVec.end(); it++){
		int itLength = (*it).length();
		string name = (*it).substr(0, itLength -2);
		int type = stoi((*it).substr(itLength -1, 1));
		
		if(type == 1){
			players.push_back(new PlayerType1(name, position));
		}
		else if(type == 2){
			players.push_back(new PlayerType2(name, position));
		}
		else if(type == 3){
			players.push_back(new PlayerType3(name, position));
		}
		else if(type == 4){
			players.push_back(new PlayerType4(name, position));
		}
		else{
			throw invalid_argument("The player type is invalid!!!");
		}

		position++;
	}

	return players;
}

bool Game::isVerbal() const {

	return verbal;
}

bool Game::areWinners(){

	return winners.size() != 0;
}

bool Game::singleWinner(){

	return winners.size() == 1;
}

void Game::deal(){

	for(vector<Player *>::iterator it = players.begin(); it != players.end(); it++){

		(*it)->fetchFromDeck(deck, 7);
	}
}

void Game::init() {
	
	deal();
}

vector<Player *> Game::getPlayers() const {

	return players;
}

void Game::printState(){

	cout << "Deck: " << deck.toString() << endl;
	for(vector<Player *>::iterator it = players.begin(); it != players.end(); it++){

		cout << (*it)->toString() << endl;
	}
}

void Game::printNumberOfTurns(){

	cout << "Number of turns: " << turn << endl;
}

void Game::printWinner(){

	if(singleWinner()){

		cout << "***** The Winner is: " << winners[0]->getName() << " *****" << endl;
	}
	else{
		string winnersNames = winners[0]->getName() + " and " + winners[1]->getName();
		cout << "***** The winners are: " << winnersNames << " *****" << endl;
	}
}

void Game::printTurn(){

	cout << "Turn " << turn << endl;
	printState();
}

void Game::play(){

	while(!areWinners()){

		for(vector<Player *>::iterator it = players.begin(); it != players.end(); it++){
			
			if(isVerbal()){
				printTurn();
			}
			
			(*it)->goTurn(players, deck);
			
			Player* chosenPlayer = players[(*it)->getChosenPlayerPosition()];
			
			if(isVerbal()){
				cout << (*it)->getName()  << " asked " << chosenPlayer->getName()  << " for the value " << (*it)->getChosenCardValue() << endl;
				cout << endl;
			}

			if((*it)->didIwin()){
				winners.push_back((*it));
			}
				
			if(chosenPlayer->didIwin()){
				winners.insert(winners.begin(), chosenPlayer);
			}

			if(areWinners()){
				break;
			}

			turn++;

		}
	}
}

int Game::getHighestNumericValue() const {

	return highestNumericValue;
}

int Game::getTurn() const {

	return turn;
}

Deck Game::getDeck() const {

	return deck;
}

vector<Player *> Game::getWinners() const {

	return winners;
}

void Game::copy(const Game& otherGame) {
	
	this->verbal = otherGame.isVerbal();
	this->highestNumericValue = otherGame.getHighestNumericValue();
	this->turn = otherGame.getTurn();
	
	Deck otherDeckv = Deck(otherGame.getDeck());
	this->deck = otherDeckv;

	vector<Player*> otherPlayers = otherGame.getPlayers();
	vector<Player*> newPlayers;


	for(vector<Player*>::iterator it = otherPlayers.begin() ; it != otherPlayers.end(); it++){

		cout << "it: " << (*it)->toString() << endl;
		Player* tempPlayer;

		if((*it)->getPlayerType() == 1) {
			cout << "it inside first if: " << (*it)->toString() << endl;
			tempPlayer = new PlayerType1((**it));
			cout << "it after first if: " << (*it)->toString() << endl;
		}
		else if((*it)->getPlayerType() == 2) {
			tempPlayer = new PlayerType2((**it));
		}
		else if((*it)->getPlayerType() == 3) {
			tempPlayer = new PlayerType3((**it));
		}
		else if((*it)->getPlayerType() == 4) {
			tempPlayer = new PlayerType4((**it));
		}

		cout << "it before push: " << (*it)->toString() << endl;
		newPlayers.push_back(tempPlayer);
	}

	this->players = newPlayers;


	vector<Player*> otherWinners = otherGame.getWinners();
	vector<Player*> newWinners;

	for(vector<Player*>::iterator it = otherWinners.begin() ; it != otherWinners.end(); it++){

		Player* tempWinner;

		if((*it)->getPlayerType() == 1) {
			tempWinner = new PlayerType1((**it));
		}
		else if((*it)->getPlayerType() == 2) {
			tempWinner = new PlayerType2((**it));
		}
		else if((*it)->getPlayerType() == 3) {
			tempWinner = new PlayerType3((**it));
		}
		else if((*it)->getPlayerType() == 4) {
			tempWinner = new PlayerType4((**it));
		}

		newWinners.push_back(tempWinner);
	}

	this->winners = newWinners;
}
