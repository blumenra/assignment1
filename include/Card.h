#ifndef CARD_H_
#define CARD_H_

#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

enum Shape {
	Club,
	Diamond,
	Heart,
	Spade
};

enum Figure {
	Jack,
	Queen,
	King,
	Ace
};

class Hand;
class Card {
private:
  	Shape shape;
public:
 	Card(Shape shape);

	virtual string toString() = 0; //Returns the string representation of the card "<value><shape>" exp: "12S" or "QD"
 	Shape getShape();
 	string shapeToString(Shape shape);
 	virtual ~Card();
 	virtual string getStrValue() = 0;
 	virtual vector<int> valuateMe(Hand& hand) = 0;
 	// virtual Card& operator=(const Card& otherCard) = 0;
 	// void setShape(Shape shape);
 	virtual bool isFigure() = 0;
 	virtual bool isNumeric();
};

class FigureCard : public Card {
private:
	Figure figure;

	string figureToString(Figure figure);
	Figure stringToFigure(string strFigure);
public:
	FigureCard(Shape shape, Figure figure);
	FigureCard(Card& otherFigureCard);
	string getStrValue();
	virtual string toString() override;
	vector<int> valuateMe(Hand& hand) override;
	bool isFigure();
	// Card& operator=(const Card& otherFigureCard);
};

class NumericCard : public Card {
private:
	int number;
public:
	NumericCard(Shape shape, int number);
	NumericCard(Card& otherNumericCard);
	string getStrValue();
	virtual string toString() override;
	vector<int> valuateMe(Hand& hand) override;
	Card& operator=(Card& otherCard);
	bool isFigure();

};

#endif
