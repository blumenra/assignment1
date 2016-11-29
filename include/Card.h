#ifndef CARD_H_
#define CARD_H_

#include <iostream>
#include <vector>

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
 	Shape getShape() const;
 	string shapeToString(Shape shape);
 	virtual ~Card();
 	virtual string getStrValue() = 0;
 	virtual vector<int> valuateMe(Hand& hand) = 0;
};

class FigureCard : public Card {
private:
	Figure figure;
	string figureToString(Figure figure) const;
public:
	FigureCard(Shape shape, Figure figure);
	string getStrValue();
	virtual string toString() override;
	vector<int> valuateMe(Hand& hand) override;
};

class NumericCard : public Card {
private:
	int number;
public:
	NumericCard(Shape shape, int number);
	string getStrValue();
	virtual string toString() override;
	vector<int> valuateMe(Hand& hand) override;
};

#endif
