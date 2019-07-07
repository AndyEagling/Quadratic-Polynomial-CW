#include "Polynomial.h"
#include <iostream>
using namespace std;

/** constructor **/
Polynomial::Polynomial(int coefficientArray[], int size) {

	/** create on the heap **/
	coefficientSize = size;
	coefficient = new int[coefficientSize];
	/** set the values of coefficients**/
	for (int i = 0; i < coefficientSize; i++) {
		coefficient[i] = coefficientArray[i];
	}
	

}

/** constructor **/
Polynomial::Polynomial() {


}


/** Desconstructor **/
Polynomial::~Polynomial() {

	if (coefficient != nullptr) {
		
 		delete[] this->coefficient;
	}

}



/** get the value of a selected coefficient given an index **/
int Polynomial::getCoefficient(int position) {

	return coefficient[position];

}


/** get the size of the polynomial **/
int Polynomial::getSize() {

	return coefficientSize;

}


/** get the value of the polynomial given a value of x **/
int Polynomial::computeValue(int valueX) {
	
	int totalValue = 0;
	/** for all the coefficients **/
	for (int i = 0; i < coefficientSize; i++) {

		int value = 1;
		/** using the degree to calclulate the amount of times it needs to be times by X **/
		/** coefficientSize - i gets - 1 gets the power of x **/
		for (int y = (coefficientSize - i - 1); y > 0; y--) {
			value = (value * valueX);
		}
		/** then times by the coefficient **/
		value = (value * coefficient[i]);

		/** update total **/
		totalValue = totalValue + value;
	}

	return totalValue;

}


/** Add two polynomials together returning a new one **/
Polynomial Polynomial::operator+(Polynomial rhs) {

	/** find highest degree and difference **/
	int degree;
	int difference = 0;
	if (rhs.getSize() > this->coefficientSize) {
		degree = rhs.getSize();
		difference = degree - this->coefficientSize;
	}
	else {
		degree = this->coefficientSize;
		difference = degree - rhs.getSize();
	}

	const int polySize = degree;

	/** create array to hold coefficients **/
	int *tempArray = new int[polySize];

	/** initalise array with 0's **/
	for (int i = 0; i < polySize; i++) {
		tempArray[i] = 0;
	}
	/** if rhs is bigger **/
	if (rhs.getSize() > this->coefficientSize) {
		/** add this coefficient values **/
		for (int i = 0; i < coefficientSize; i++) {
			tempArray[i + difference] = this->coefficient[i];
		}

		/** add rhs coefficient values **/
		for (int i = 0; i < rhs.getSize(); i++) {
			tempArray[i] = tempArray[i] + rhs.getCoefficient(i);
		}
	}
	/** if this poly is bigger **/
	else {
		/** add this coefficient values **/
		for (int i = 0; i < coefficientSize; i++) {
			tempArray[i] = this->coefficient[i];
		}

		/** add rhs coefficient values **/
		for (int i = 0; i < rhs.getSize(); i++) {
			tempArray[i + difference] = tempArray[i + difference] + rhs.getCoefficient(i);
		}

	}
		
	/** create a new polynomial **/
	Polynomial returnPoly = Polynomial(tempArray, polySize);
	return returnPoly;
}



Polynomial Polynomial::operator-(Polynomial rhs) {

	/** find highest degree and difference **/
	int degree;
	int difference = 0;
	if (rhs.getSize() > this->coefficientSize) {
		degree = rhs.getSize();
		difference = degree - this->coefficientSize;
	}
	else {
		degree = this->coefficientSize;
		difference = degree - rhs.getSize();
	}

	const int polySize = degree;

	/** create array to hold coefficients **/
	int *tempArray = new int[polySize];

	/** initalise array with 0's **/
	for (int i = 0; i < polySize; i++) {
		tempArray[i] = 0;
	}
	/** if rhs is bigger **/
	if (rhs.getSize() > this->coefficientSize) {
		/** add this coefficient values **/
		for (int i = 0; i < coefficientSize; i++) {
			tempArray[i + difference] = this->coefficient[i];
		}

		/** subtract rhs coefficient values **/
		for (int i = 0; i < rhs.getSize(); i++) {
			tempArray[i] = tempArray[i] - rhs.getCoefficient(i);
		}
	}

	/** if this poly is bigger **/
	else {
		/** add this coefficient values **/
		for (int i = 0; i < coefficientSize; i++) {
			tempArray[i] = this->coefficient[i];
		}

		/** subtract rhs coefficient values **/
		for (int i = 0; i < rhs.getSize(); i++) {
			tempArray[i + difference] = tempArray[i + difference] - rhs.getCoefficient(i);
		}

	}

	/** create a new polynomial **/
	Polynomial returnPoly = Polynomial(tempArray, polySize);
	return returnPoly;
}


Polynomial& Polynomial::operator+=(Polynomial rhs) {

	/** find highest Size and difference **/
	int highestSize = this->coefficientSize;
	int difference = 0;
	if (rhs.getSize() > this->coefficientSize) {
		highestSize = rhs.getSize();
		difference = highestSize - this->coefficientSize;
	}
	else {
		highestSize = this->coefficientSize;
		difference = highestSize - rhs.getSize();
	}

	const int polySize = highestSize;

	/** create array to hold coefficients **/
	int *tempArray = new int[polySize];

	/** initalise array with 0's **/
	for (int i = 0; i < polySize; i++) {
		tempArray[i] = 0;
	}

	/** if the rhs is bigger **/
	if (rhs.getSize() > this->coefficientSize) {
		/** add this coefficient values **/
		for (int i = 0; i < coefficientSize; i++) {
			tempArray[i + difference] = this->coefficient[i];
		}

		/** add rhs coefficient values **/
		for (int i = 0; i < rhs.getSize(); i++) {
			tempArray[i] = tempArray[i] + rhs.getCoefficient(i);
		}
	}
	/** if this poly is bigger **/
	else {
		/** add this coefficient values **/
		for (int i = 0; i < coefficientSize; i++) {
			tempArray[i] = this->coefficient[i];
		}

		/** add rhs coefficient values **/
		for (int i = 0; i < rhs.getSize(); i++) {
			tempArray[i + difference] = tempArray[i + difference] + rhs.getCoefficient(i);
		}

	}

	/** update polynomial **/
	this->coefficient = tempArray;
	this->coefficientSize = highestSize;

	return *this;
}


Polynomial& Polynomial::operator-=(Polynomial rhs) {

	/** find highest Size and difference **/
	int highestSize = this->coefficientSize;
	int difference = 0;
	if (rhs.getSize() > this->coefficientSize) {
		highestSize = rhs.getSize();
		difference = highestSize - this->coefficientSize;
	}
	else {
		highestSize = this->coefficientSize;
		difference = highestSize - rhs.getSize();
	}

	const int polySize = highestSize;

	/** create array to hold coefficients **/
	int *tempArray = new int[polySize];

	/** initalise array with 0's **/
	for (int i = 0; i < polySize; i++) {
		tempArray[i] = 0;
	}

	/** if the rhs is bigger **/
	if (rhs.getSize() > this->coefficientSize) {
		/** add this coefficient values **/
		for (int i = 0; i < coefficientSize; i++) {
			tempArray[i + difference] = this->coefficient[i];
		}

		/** subtract rhs coefficient values **/
		for (int i = 0; i < rhs.getSize(); i++) {
			tempArray[i] = tempArray[i] - rhs.getCoefficient(i);
		}
	}
	/** if this poly is bigger **/
	else {
		/** add this coefficient values **/
		for (int i = 0; i < coefficientSize; i++) {
			tempArray[i] = this->coefficient[i];
		}

		/** subtract rhs coefficient values **/
		for (int i = 0; i < rhs.getSize(); i++) {
			tempArray[i + difference] = tempArray[i + difference] - rhs.getCoefficient(i);
		}

	}

	/** update polynomial **/
	this->coefficient = tempArray;
	this->coefficientSize = highestSize;

	return *this;
} 


bool Polynomial::operator==(Polynomial rhs) {

	/** since 0x^2 + 0x + 1 == 1 we cant just straight up compare each equiv index as index 2 in the lhs = 1 and index 0 in rhs = 1**/

	/** find amount of comparable values (minSize) and differences **/
	int minSize;
	//differenceLHS and difference RHS are used to calculate what extra should be added to i when finding the correct coefficient to asses.
	//finding both integers from rhs and lhs could be at difference positions.
	//for example poly1 could be = 0x + 1 and poly2 = 1. Poly 2 index 0 should be compared with poly1 index 1.
	//in the example they are both logically equal but have differenct sizes and therefore this needs to be calculated
	int differenceLHS= 0;
	int differenceRHS = 0;

	/** if RHS is bigger **/
	if (rhs.getSize() > this->getSize()) {
		minSize = this->getSize();
		differenceRHS = rhs.getSize() - this->getSize();

		//since RHS bigger check the values that wont be compared below are = 0 otherwise not equal
		for (int i = 0; i < differenceRHS; i++) {
			if (rhs.getCoefficient(i) == 0) {
				/** good = 0 therefore can be equal **/
			}
			else {
				/** not = 0 therfore not equal **/
				return false;
			}
		}
	}

	/** if LHS is bigger **/
	else {
		minSize = rhs.getSize();
		differenceLHS = this->getSize() - rhs.getSize();

		//since LHS bigger check the values that wont be compared below are = 0 otherwise not equal
		for (int i = 0; i < differenceLHS; i++) {
			if (this->getCoefficient(i) == 0) {
				/** good = 0 therefore can be equal **/
			}
			else {
				/** not = 0 therfore not equal **/
				return false;
			}
		}
	}

	/** for each coefficient comparable**/
	for (int i = 0; i < minSize; i++) {

		/** use cout methods below to prove that LHS and RHS difference are working properly **/
		//cout << "\nLHS poly at index " << i << " :\n";
		//cout << this->getCoefficient(i + differenceLHS);
		//cout << "\nRHS poly at index " << i << " :\n";
		//cout << rhs.getCoefficient(i + differenceRHS);

		/** check if equal **/
		if (this->getCoefficient(i+differenceLHS) == rhs.getCoefficient(i+differenceRHS)) {
			/** good **/
		}
		else {
			/** otherwise throw false **/
			return false;
		}
	}

	/** must be true then **/
	return true;
}


bool Polynomial::operator!=(Polynomial rhs) {

	/** call == operator **/
	if(this->operator==(rhs)) {
		/** equal therefore return false **/
		return false;
	}
	else {
		/** false therefore return true **/
		return true;
	}
	
}


Polynomial Polynomial::operator*(Polynomial rhs) {

	/** find the amount of integers that the aray will need to be **/
	int highestSize = (this->getSize()) + (rhs.getSize()) -1;
	
	/** create temp array to store the values from multiplication and initialise with 0's **/
	int *tempArray = new int[highestSize];
	for (int i = 0; i < highestSize; i++) {
		tempArray[i] = 0;
	}

	/** loop through the coefficients of this polynomial starting at integer (highest index)**/
	for (int i = this->getSize() - 1; i >= 0; i--) {

		/** loop through the coefficients of RHS polynomial multiplying and adding to the array **/
		for (int y = rhs.getSize() - 1; y >= 0; y--) {
			tempArray[i + y] = tempArray[i+y] + ((this->getCoefficient(i)) * (rhs.getCoefficient(y)));

		}
	}
	/** create the new polynomial **/
	Polynomial output = Polynomial(tempArray, highestSize);
	return output;

}


Polynomial& Polynomial::operator*=(Polynomial rhs) {
	
	/** find the amount of integers that the aray will need to be **/
	int highestSize = (this->getSize()) + (rhs.getSize()) - 1;

	/** create temp array to store the values from multiplication and initialise with 0's **/
	int *tempArray = new int[highestSize];
	for (int i = 0; i < highestSize; i++) {
		tempArray[i] = 0;
	}

	/** loop through the coefficients of this polynomial starting at integer (highest index)**/
	for (int i = this->getSize() - 1; i >= 0; i--) {

		/** loop through the coefficients of RHS polynomial multiplying and adding to the array **/
		for (int y = rhs.getSize() - 1; y >= 0; y--) {
			tempArray[i + y] = tempArray[i + y] + ((this->getCoefficient(i)) * (rhs.getCoefficient(y)));

		}
	}
	/** update this poly **/
	coefficient = tempArray;
	return *this;
}

/** assignment operator overwrites current coefficients with new ones **/
Polynomial& Polynomial::operator=(Polynomial rhs) {

	/** set array to be the size of rhs poly **/
	int newSize = rhs.getSize();
	int *coefficient = new int[newSize];

	/** get values **/
	for (int i = 0; i < newSize; i++) {
		this->coefficient[i] = rhs.getCoefficient(i);
	}

	/** update coefficient size **/
	this->coefficientSize = rhs.getSize();
	return *this;
}


/** copy operator creates a new polynomial equal to the current polynomial **/
Polynomial::Polynomial(Polynomial& rhs) {

	/** set array to be the size of rhs poly **/
	this->coefficientSize = rhs.getSize();
	coefficient = new int[coefficientSize];

	/** set values **/
	for (int i = 0; i < coefficientSize; i++) {
		coefficient[i] = rhs.getCoefficient(i);
	}

}


/** output **/
ostream & operator<<(ostream & output, Polynomial & poly){
	
	/** for each coefficient add to output string **/
	for (int i = 0; i < poly.getSize() - 1; i++) {
		output << poly.getCoefficient(i) << "X^" << (poly.getSize() - 1 - i) << " + ";
	}
	/** output final value outside of loop so that the + isnt included on the end **/
	output << poly.getCoefficient(poly.getSize() - 1);

	return output;

}


/** input **/
istream & operator>>(istream & input, Polynomial & poly){


	cout << "\nInput the amount of coefficients that you would like this polynomial to have: ";
	cin >> poly.coefficientSize;
	poly.coefficient = new int[poly.coefficientSize];
	

	/** for each coefficient add to input **/
	for (int i = 0; i < poly.getSize(); i++) {
		cout << "\nInput the coefficient for the value of x^" << (poly.getSize() - 1 - i) << ": ";
		input >> poly.coefficient[i];
	}

	return input;
}



