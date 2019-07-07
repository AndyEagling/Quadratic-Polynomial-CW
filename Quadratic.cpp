#include "Quadratic.h"
#include <iostream>
using namespace std;


Quadratic::Quadratic(int coefficientA, int coefficientB, int coefficientC) {

	/** update the values of the variables **/
	coefficient[0] = coefficientA;
	coefficient[1] = coefficientB;
	coefficient[2] = coefficientC;
	
}


Quadratic::Quadratic() {

}


/** return the coefficient of a given power of x **/
int Quadratic::getCoefficient(int position) {
	if (position == 1) {
		return this->coefficient[0];
	}
	else if(position == 2){
		return this->coefficient[1];
	}
	else if (position == 3) {
		return this->coefficient[2];
	}
	else {
		throw "invalid position! needs to be between 1 and 3";
	}
}


/** compute the value of the quadratic given a value of x **/
int Quadratic::computeValue(int valueX) {
	/** add first coefficient **/
	int value = (this->coefficient[0] * (valueX * valueX));
	/** add second coefficient **/
	value = value + (this->coefficient[1] * valueX);
	/** add third coefficient **/
	value = value + this->coefficient[2];
	return value;
}


/** overload + operator to add the two quadratics, outputing a new quadratic **/
Quadratic Quadratic::operator+(Quadratic rhs) {
	/** calculate the new coefficients **/
	int newCoefficientOne = this->coefficient[0] + rhs.getCoefficient(1);
	int newCoefficientTwo = this->coefficient[1] + rhs.getCoefficient(2);
	int newCoefficientThree = this->coefficient[2] + rhs.getCoefficient(3);
	/** return the new quadratic **/
	return Quadratic(newCoefficientOne, newCoefficientTwo, newCoefficientThree);
}


/** overload - operator to subtract the two quadratics, outputing a new quadratic **/
Quadratic Quadratic::operator-(Quadratic rhs) {
	/** calculate the new coefficients by updating the current coefficient values **/
	int newCoefficientOne = this->coefficient[0] - rhs.getCoefficient(1);
	int newCoefficientTwo = this->coefficient[1] - rhs.getCoefficient(2);
	int newCoefficientThree = this->coefficient[2] - rhs.getCoefficient(3);
	/** return the new quadratic **/
	return Quadratic(newCoefficientOne, newCoefficientTwo, newCoefficientThree);
}


Quadratic &Quadratic::operator+=(Quadratic rhs){

	/** calculate the new coefficients. Save the value to the current quadratic variables**/
	this->coefficient[0] += rhs.getCoefficient(1);
	this->coefficient[1] += rhs.getCoefficient(2);
	this->coefficient[2] += rhs.getCoefficient(3);

	Quadratic newQuad = Quadratic(this->coefficient[0], this->coefficient[1], this->coefficient[2]);
	return newQuad;
}


/** overload +- operator to subtract the two quadratics, outputing a the same quadratic **/
Quadratic& Quadratic::operator-=(Quadratic rhs) {

	/** calculate the new coefficients. Save the value to the current quadratic variables**/
	this->coefficient[0] -= rhs.getCoefficient(1);
	this->coefficient[1] -= rhs.getCoefficient(2);
	this->coefficient[2] -= rhs.getCoefficient(3);

	Quadratic newQuad = Quadratic(this->coefficient[0], this->coefficient[1], this->coefficient[2]);
	return newQuad;
}


/** overload == operator to check if the quadratics are logically equal, outputting a boolean **/
bool Quadratic::operator==(Quadratic rhs) {
	/** logically equal therefore return true **/
	if (this->coefficient[0] == rhs.getCoefficient(1) && this->coefficient[1] == rhs.getCoefficient(2) && this->coefficient[2] == rhs.getCoefficient(3)) {
		return true;
	}
	/** otherwise return false **/
	else {
		return false;
	}
}


/** overload != operator to check if the quadratics are not logically equal, outputting a boolean **/
bool Quadratic::operator!=(Quadratic rhs) {
	/** logically equal therefore return false**/
	if (this->coefficient[0] == rhs.getCoefficient(1) && this->coefficient[1] == rhs.getCoefficient(2) && this->coefficient[2] == rhs.getCoefficient(3)) {
		return false;
	}
	/** otherwise return true **/
	else {
		return true;
	}
}

/** output **/
ostream& operator<< (ostream &output, Quadratic &quadratic) {

	output << quadratic.getCoefficient(1) << "X^2 + " << quadratic.getCoefficient(2) << "X + " << quadratic.getCoefficient(3);

	return output;
}


/** input **/
istream& operator>> (istream &input, Quadratic &quadratic) {

	cout << "\nInput the coefficient for the value of x^2 :";
	input >> quadratic.coefficient[0];
	cout << "\nInput the coefficient for the value of x :";
	input >> quadratic.coefficient[1];
	cout << "\nInput the coefficient for the value of the integer :";
	input >> quadratic.coefficient[2];

	return input;
}