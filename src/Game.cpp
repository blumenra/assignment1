#include <Game.h>

// Game::Game(char* configurationFile) {

// 	vector<string> configFileVec = parseConfigFile(configurationFile);
// 	this->verbal = stoi(configFileVec[0]);
// 	this->highestNumericValue = stoi(configFileVec[1]);


// }

vector<string> Game::parseConfigFile(char* configurationFile) {

	vector<string> configFileVec;
	ifstream file;
	file.open("removeMe/configurationFiles/config1.txt");
	string line;
	

	while(getline(file, line)){
		if(!line.empty() && (line.at(0) != '#')) {
			cout << line << endl;
			configFileVec.push_back(line);
		}
	}

	return configFileVec;
}

vector<Card*> Game::cardsForDeckCreator(string parsedDeck) {

	stringstream parsedDeckss(parsedDeck);

	vector<Card*> cards;
	
	vector<string> strCards;
	while(parsedDeckss.good()){
		string substr;
		getline(parsedDeckss, substr, ' ');
		strCards.push_back( substr );
	}

	for(vector<string>::iterator it = strCards.begin() ; it != strCards.end(); it++){
		// cout << "input string: " << *it << endl;
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