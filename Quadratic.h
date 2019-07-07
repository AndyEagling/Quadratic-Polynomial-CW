#pragma once
#include <ioStream>
using namespace std;

class Quadratic{

public:
	Quadratic::Quadratic(int coefficientA, int coefficientB, int coefficientC);
	Quadratic::Quadratic();
	int getCoefficient(int position);
	int computeValue(int valueX);
	Quadratic Quadratic::operator+(Quadratic rhs);
	Quadratic Quadratic::operator-(Quadratic rhs);
	Quadratic& operator+=(Quadratic rhs);
	Quadratic& operator-=(Quadratic rhs);
	bool Quadratic::operator==(Quadratic rhs);
	bool Quadratic::operator!=(Quadratic rhs);
	friend ostream& operator<< (ostream &output, Quadratic &quadratic);
	friend istream& operator>> (istream &input, Quadratic &quadratic);

private:
	int coefficient[3];
};