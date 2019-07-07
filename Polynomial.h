#pragma once
#include <ioStream>
using namespace std;

class Polynomial {

public:
	Polynomial::Polynomial(int coefficientArray[], int size);
	Polynomial::Polynomial();
	Polynomial::~Polynomial();
	int Polynomial::getCoefficient(int position);
	int Polynomial::getSize();
	int Polynomial::computeValue(int valueX);
	Polynomial Polynomial::operator+(Polynomial rhs);
	Polynomial Polynomial::operator-(Polynomial rhs);
	Polynomial& Polynomial::operator+=(Polynomial rhs);
	Polynomial& Polynomial::operator-=(Polynomial rhs);
	bool Polynomial::operator==(Polynomial rhs);
	bool Polynomial::operator!=(Polynomial rhs);
	Polynomial Polynomial::operator*(Polynomial rhs);
	Polynomial& Polynomial::operator*=(Polynomial rhs);
	Polynomial& Polynomial::operator=(Polynomial rhs);
	Polynomial::Polynomial(Polynomial& rhs);
	friend ostream& Polynomial::operator<< (ostream &output, Polynomial  &poly);
	friend istream& Polynomial::operator>> (istream &input, Polynomial &poly);

private:
	int coefficientSize;
	int *coefficient = nullptr;
};