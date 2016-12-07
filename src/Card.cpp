#include <Card.h>
#include <Hand.h>

// Card constructor
Card::Card(Shape shape):
shape(shape)
{}

Shape Card::getShape() const {
	return this->shape;
}

string Card::shapeToString(Shape shape) {
	
	switch(shape) {
		case Club:
			return "C";
		case Diamond:
			return "D";
		case Heart:
			return "H";
		case Spade:
			return "S";
		default:
			throw invalid_argument("The shape is invalid!!!");
	}
}

Card::~Card() {}


/**FigureCard constructor**/
FigureCard::FigureCard(Shape shape, Figure figure):
Card(shape),
figure(figure)
{}

FigureCard::FigureCard(Card& otherFigureCard):
Card(otherFigureCard.getShape()),
figure(stringToFigure(otherFigureCard.getStrValue()))
{}

string FigureCard::getStrValue() {
	
	return this->toString().substr(0, toString().length()-1);
}

string FigureCard::toString() {

	string strFigure = figureToString(this->figure);
	string strShape = shapeToString(this->getShape());
	string strCard = strFigure + strShape;

	return strCard;
}

string FigureCard::figureToString(Figure figure) const {
		
	switch(figure) {
		case Jack:
			return "J";
		case Queen:
			return "Q";
		case King:
			return "K";
		case Ace:
			return "A";
		default:
			throw invalid_argument("The figure is invalid!!!");
	}
}

vector<int> FigureCard::valuateMe(Hand& hand) {

	return hand.findCardsByValue(*this);
}


Figure FigureCard::stringToFigure(string strFigure) const {
	
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



/**NumericCard constructor**/
NumericCard::NumericCard(Shape shape, int number):
Card(shape),
number(number)
{}

NumericCard::NumericCard(Card& otherNumericCard):
Card(otherNumericCard.getShape()),
number(stoi(otherNumericCard.getStrValue()))
{}

string NumericCard::getStrValue() {
	
	return this->toString().substr(0, toString().length()-1);
}

string NumericCard::toString() {

	string strnNumber = to_string(this->number);
	string strShape = shapeToString(this->getShape());
	string strCard = strnNumber + strShape;

	return strCard;
}

vector<int> NumericCard::valuateMe(Hand& hand) {
	
	return hand.findCardsByValue(*this);
}


