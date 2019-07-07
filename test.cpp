#include <stdio.h>
#include <iostream>
#include <string>
#include "Quadratic.h"
#include "Polynomial.h"
using namespace std;


int main() {

	/** TESTING QUADRATIC **/

	cout << "Quadratic testing";

	/** quadratic A coefficients **/
	int a1 = 2;
	int a2 = 3;
	int a3 = 4;
	/** quadratic b coefficients **/
	int b1 = 4;
	int b2 = 4;
	int b3 = 4;

	/** quadratic values given a x value **/
	int x = 2;
	int aValue = 18;
	int bValue = 28;



	cout << "testing quadratic: \n";

	/** creating a quadratic on the stack (2x^2 + 3x + 4) **/
	Quadratic a = Quadratic(a1, a2, a3);

	/** creating a quadratic on the stack (4x^2 + 4x + 4) **/
	Quadratic b = Quadratic(b1, b2, b3);

	/** checking that it returns both quadratics values correctly **/
	cout << "\nFirst quadratic is \n";
	cout << "x^2 value    : " << a.getCoefficient(1) << "\n";
	cout << "x value      : " << a.getCoefficient(2) << "\n";
	cout << "integer value: " << a.getCoefficient(3) << "\n";
	if (a.getCoefficient(1) == a1 && a.getCoefficient(2) == a2 && a.getCoefficient(3) == a3) {
		cout << "values for first quadratic correct\n";
	}
	else {
		cout << "values for first quadratic incorrect\n";
		return 1;
	}

	cout << "\nSecond quadratic is \n";
	cout << "x^2 value    : " << b.getCoefficient(1) << "\n";
	cout << "x value      : " << b.getCoefficient(2) << "\n";
	cout << "integer value: " << b.getCoefficient(3) << "\n";
	if (b.getCoefficient(1) == b1 && b.getCoefficient(2) == b2 && b.getCoefficient(3) == b3) {
		cout << "values for first quadratic correct\n";
	}
	else {
		cout << "values for first quadratic incorrec\nt";
		return 1;
	}

	/** checking that the method to compute the total value given x **/
	cout << "\nthe value of the first quadratic when x=" << x << " is: " << a.computeValue(x);
	cout << "\nthe value of the second quadratic when x=" << x << " is: " << b.computeValue(x);
	int aComputedValue = a.computeValue(x);
	int bComputedValue = b.computeValue(x);
	if (aComputedValue == aValue && bComputedValue == bValue) {
		cout << "\nComputing values working as intended\n";
	}
	else {
		cout << "\nComputing values not working as intended\n";
		return 1;
	}


	/** testing the + operator **/
	Quadratic c = a + b;
	cout << "\nthe values of a and b added together are: \n";
	cout << "x^2 value    : " << c.getCoefficient(1) << "\n";
	cout << "x value      : " << c.getCoefficient(2) << "\n";
	cout << "integer value: " << c.getCoefficient(3) << "\n";
	if ((a1 + b1) == c.getCoefficient(1) && (a2 + b2) == c.getCoefficient(2) && (a3 + b3) == c.getCoefficient(3)) {
		cout << "+ operator working as intended\n";
	}
	else {
		cout << "+ operator not working as intended\n";
		return 1;
	}


	/** testing the - operator **/
	Quadratic d = a - b;
	cout << "\nthe values of a subtract b are: \n";
	cout << "x^2 value    : " << d.getCoefficient(1) << "\n";
	cout << "x value      : " << d.getCoefficient(2) << "\n";
	cout << "integer value: " << d.getCoefficient(3) << "\n";
	if ((a1 - b1) == d.getCoefficient(1) && (a2 - b2) == d.getCoefficient(2) && (a3 - b3) == d.getCoefficient(3)) {
		cout << "- operator working as intended\n";
	}
	else {
		cout << "- operator not working as intended\n";
		return 1;
	}


	/** testing the += operator **/
	a += b;
	/** this should make a = to the values of a+b **/
	cout << "\nthe values of a += b are: \n";
	cout << "x^2 value    : " << a.getCoefficient(1) << "\n";
	cout << "x value      : " << a.getCoefficient(2) << "\n";
	cout << "integer value: " << a.getCoefficient(3) << "\n";
	if ((a1 + b1) == a.getCoefficient(1) && (a2 + b2) == a.getCoefficient(2) && (a3 + b3) == a.getCoefficient(3)) {
		cout << "+= operator working as intended\n";
	}
	else {
		cout << "+= operator not working as intended\n";
		return 1;
	}


	/** testing the -= operator **/
	a -= b;
	/** this should return it to the normal a values because of the += above **/
	cout << "\nthe values of a -= b are: \n";
	cout << "x^2 value    : " << a.getCoefficient(1) << "\n";
	cout << "x value      : " << a.getCoefficient(2) << "\n";
	cout << "integer value: " << a.getCoefficient(3) << "\n";
	if ((a1) == a.getCoefficient(1) && (a2) == a.getCoefficient(2) && (a3) == a.getCoefficient(3)) {
		cout << "-= operator working as intended\n";
	}
	else {
		cout << "-= operator not working as intended\n";
		return 1;
	}


	/** testing the == operator/
	/** creating a new quadratic logically equal to a **/
	Quadratic e = Quadratic(a1, a2, a3);
	/** checking it returns true if they are logically equal **/
	if (a == e) {
		cout << "\n== operator working for logically matching strings";
	}
	else {
		cout << "\n== operator not working for logically matching strings";
		return 1;
	}
	/** checking it reuturns false if they arent logically equal **/
	if (a == b) {
		cout << "\n== operator not working for logically not matching strings\n";
		return 1;
	}
	else {
		cout << "\n== operator working for logically not matching strings\n";
	}


	/** testing the != operator/
	/** checking it returns true if they are logically equal **/
	if (a != e) {
		cout << "\n!= operator not working for logically matching strings";
		return 1;
	}
	else {
		cout << "\n!= operator working for logically matching strings";
	}
	/** checking it reuturns false if they arent logically equal **/
	if (a != b) {
		cout << "\n!= operator working for logically not matching strings\n";
	}
	else {
		cout << "\n!= operator not working for logically not matching strings\n";
		return 1;
	}



	cout << "\nAll test on Quadratic ran have worked as intended\n";






	/** TESTING POLYNOMIAL **/

	cout << "\nPolynomial Testing:\n";

	/** creating two random polynomials **/
	const int poly1size = 4;
	const int poly2size = 6;

	int polynomialArray1[poly1size] = {4, 0, 0, -1};
	int polynomialArray2[poly2size] = { 2, 1, 1, 5, 3, 2 };

	Polynomial poly1 = Polynomial(polynomialArray1, poly1size);
	Polynomial poly2 = Polynomial(polynomialArray2, poly2size);

	/** checking the getCoefficient function works and that the polynomials are created properly **/
	cout << "\nValues of polynomial 1:\n";
	for (int i = 0; i < poly1size; i++) {
		cout << poly1.getCoefficient(i);
		cout << "\n";
	}
	cout << "\nValues of polynomial 2:\n";
	for (int i = 0; i < poly2size; i++) {
		cout << poly2.getCoefficient(i) << "\n";
	}

	/** testing the compute function with a value of x **/
	int polyX = 2;
	cout << "\nValue of poly1 when x = " << polyX << "\n";
	cout << poly1.computeValue(polyX) << "\n";
	/** the expected value of poly1 when x=2 should be 31 ((4*(2^3)) + (0*(2^2)) + (0*(2^1)) + -1 = 31) **/
	cout << "Expected: 31\n";

	cout << "\nValue of poly2 when x = " << polyX << "\n";
	cout << poly2.computeValue(polyX) << "\n";
	/** the expected value of poly2 when x=2 should be   (2*(2^5)) + (1*(2^4)) + (1*(2^3)) + (5*(2^2)) + (3*(2*1)) + 2 = 116 **/
	cout << "Expected: 116\n";


	/** testing poly + poly in both directions **/
	Polynomial poly3 = poly1 + poly2;
	Polynomial poly4 = poly2 + poly1;
	/** expected = (2+0) + (1+0)  + (1+4) + (5+0) + (3+0) + (2+-1) = 2,1,5,5,3,1 **/
	int expectedArray[6] = { 2,1,5,5,3,1 };
	cout << "\nPolynomial 1 + polynomail 2:\n";
	for (int i = 0; i < poly3.getSize(); i++) {
		cout << "index " << i << " = " << poly3.getCoefficient(i);
		if (poly3.getCoefficient(i) == expectedArray[i]) {
			cout << " This is the correct value!\n";
		}
		else {
			cout << " This is the incorrect value!\n";
			return 1;
		}
	}
	cout << "\nPolynomial 2 + polynomail 1:\n";
	for (int i = 0; i < poly3.getSize(); i++) {
		cout << "index " << i << " = " << poly4.getCoefficient(i);
		if (poly4.getCoefficient(i) == expectedArray[i]) {
			cout << " This is the correct value!\n";
		}
		else {
			cout << " This is the incorrect value!\n";
			return 1;
		}
	}
	

	/** testing poly - poly in both directions **/
	Polynomial poly5 = poly3 - poly1;
	//expect poly 2
	cout << "\nPolynomial 3 - polynomail 1:\n";
	for (int i = 0; i < poly5.getSize(); i++) {
		cout << "index " << i << " = " << poly5.getCoefficient(i);
		if (poly5.getCoefficient(i) == poly2.getCoefficient(i)) {
			cout << " This is the correct value!\n";
		}
		else {
			cout << " This is the incorrect value!\n";
		}
	}

	Polynomial poly6 = poly4 - poly2;
	//expect 0,0,4,0,0,-1 (poly 1 but there is the two coefficients above due to the subtraction) 
	int expectedArray2[6] = { 0,0,4,0,0,-1 };
	cout << "\nPolynomial 4 - polynomail 2:\n";
	for (int i = 0; i < poly6.getSize(); i++) {
		cout << "index " << i << " = " << poly6.getCoefficient(i);
		if (poly6.getCoefficient(i) == expectedArray2[i]) {
			cout << " This is the correct value!\n";
		}
		else {
			cout << " This is the incorrect value!\n";
		}
	}


	/** testing += **/
	poly1 += poly2;
	cout << "\nTesting poly1 += poly2\n";
	//expected to equal poly3 **/
	for (int i = 0; i < poly1.getSize(); i++) {
		cout << "index " << i << " = " << poly1.getCoefficient(i);
		if (poly1.getCoefficient(i) == poly3.getCoefficient(i)) {
			cout << " This is the correct value!\n";
		}
		else {
			cout << " This is the incorrect value!\n";
		}
	}

	/** testing -= **/
	poly1 -= poly2;
	cout << "\nTesting poly1 -= poly2\n";
	//expected to equal origional poly1 values **/
	for (int i = 0; i < poly1.getSize(); i++) {
		cout << "index " << i << " = " << poly1.getCoefficient(i);
		if (poly1.getCoefficient(i) == polynomialArray1[i]) {
			cout << " This is the correct value!\n";
		}
		else {
			cout << " This is the incorrect value!\n";
		}
	}


	/** testing == and != **/
	cout << "\nTesting == \n";
	//duplicate to check should be equal 
	Polynomial poly1duplicate = Polynomial(polynomialArray1, poly1size);
	bool result = (poly1 == poly1duplicate);
	/** output the values and check if correct **/
	cout << "Polynomial 1 duplicate == polynomial 1 returns: " << result << "\n";
	if (result == 1) {
		cout << "Correct. They are logically equal\n";
	}
	else {
		cout << "Incorrect they should be logically equal\n";
		return 1;
	}
	result = (poly1 == poly2);
	cout << "Polynomial 1 == polynomial 2 return: " << result << "\n";
	if (result == 0) {
		cout << "Correct. They aren't logically equal\n";
	}
	else {
		cout << "Incorrect they shouldn't be logically equal\n";
		return 1;
	}

	cout << "\nTesting !=\n";
	result = (poly1 != poly1duplicate);
	/** output the values and check if correct **/
	cout << "Polynomial 1 duplicate != polynomial 1 returns: " << result << "\n";
	if (result == 1) {
		cout << "Incorrect. They are logically equal\n";
		return 1;
	}
	else {
		cout << "Correct they should be logically equal\n";
	}
	result = (poly1 != poly2);
	cout << "Polynomial 1 != polynomial 2 return: " << result << "\n";
	if (result == 0) {
		cout << "Incorrect. They aren't logically equal\n";
		return 1;
	}
	else {
		cout << "Correct they shouldn't be logically equal\n";
	}


	/** Testing * **/
	//expected output from multiply
	// two 0's at the start because poly 1 now is {0,0,4,0,0,-1} hence two 0's multiplied at the top 
	int multitplyExpected[11] = { 0,0,8,4,4,18,11,7,-5,-3,-2 };
	cout << "\npoly1 * poly 2: ";
	Polynomial polyMultiply = poly1*poly2;
	/** output the values and check if correct **/
	for (int i = 0; i < polyMultiply.getSize(); i++) {
		cout << "\nindex " << i << ": " << polyMultiply.getCoefficient(i);
		if (polyMultiply.getCoefficient(i) == multitplyExpected[i]) {
			cout << " Correct value";
		}
		else {
			cout << " Incorrect value, expected " << multitplyExpected[i];
			return 1;
		}
	}
	cout << "\n";


	/** Testing *= **/
	cout << "\npoly1 *= poly 2: ";
	poly1*=poly2;
	/** output the values and check if correct **/
	for (int i = 0; i < poly1.getSize(); i++) {
		cout << "\nindex " << i << ": " << poly1.getCoefficient(i);
		if (poly1.getCoefficient(i) == multitplyExpected[i]) {
			cout << " Correct value";
		}
		else {
			cout << " Incorrect value, expected " << multitplyExpected[i];
			return 1;
		}
	}
	cout << "\n";


	/** Testing copy and assignment operators **/
	cout << "\nTesting copy and assignment operators: ";
	cout << "\npoly1 = poly2";
	poly1 = poly2;
	//expect poly1 values to = poly 2 values
	for (int i = 0; i < poly1.getSize(); i++) {
		cout << "\nindex " << i << ": " << poly1.getCoefficient(i);
		if (poly1.getCoefficient(i) == poly2.getCoefficient(i)) {
			cout << " Correct value";
		}
		else {
			cout << " Incorrect value, expected " << poly2.getCoefficient(i);
			return 1;
		}

	}

	cout << "\n";

	cout << "\nPolynomial A = poly2";
	Polynomial A = poly2;
	//expect A values to = poly 2 values
	for (int i = 0; i < A.getSize(); i++) {
		cout << "\nindex " << i << ": " << A.getCoefficient(i);
		if (A.getCoefficient(i) == poly2.getCoefficient(i)) {
			cout << " Correct value";
		}
		else {
			cout << " Incorrect value, expected " << poly2.getCoefficient(i);
			return 1;
		}
	}

	cout << "\n";

	cout << "\nPolynomial Testing completed, All methods working as expected\n";

	/** Testing input and output methods **/
	cout << "\nTesting the input and output methods\n";
	Quadratic inputQuad = Quadratic();
	cin >> inputQuad;
	cout << "\nThe output from the quadratic you entered is:";
	cout << inputQuad;

	cout << "\n";

	Polynomial polyIn = Polynomial();
	cin >> polyIn;
	cout << "\nThe output from the Polynomial you entered is:";
	cout << polyIn;

	cout << "\n";

	system("pause");
	return 0;


	cout << "\nAll testing completed!";


}