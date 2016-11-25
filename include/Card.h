#ifndef CARD_H_
#define CARD_H_

#include <iostream>
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

class Card {
private:
  	Shape shape;
public:
 	Card(Shape shape);
	virtual string toString() = 0; //Returns the string representation of the card "<value><shape>" exp: "12S" or "QD"
 	Shape getShape() const;
 	string shapeToString(Shape shape);
 	virtual ~Card();
};

class FigureCard : public Card {
private:
	Figure figure;
	string figureToString(Figure figure) const;
public:
	FigureCard(Shape shape, Figure figure);
	Figure getFigure() const;
	virtual string toString() override;
};

class NumericCard : public Card {
private:
	int number;
public:
	NumericCard(Shape shape, int number);
	int getNumber() const;
	virtual string toString() override;
};

#endif
