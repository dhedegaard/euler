/*
 * euler33.cpp
 *
 *  Created on: 21/02/2011
 *      Author: Dennis Hedegaard
 */

#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

/**
 * Repressents a fraction with a numerator and a denominator.
 */
struct _fraction {
	int den;
	int num;
}typedef fraction;

// Repressents a bad or invalid fraction, 0/0.
static fraction bad;

/**
 * Attempts an incorrect cancellation, if it works a correct
 * fraction is returned, else 0/0 is returned.
 */
fraction incorrect_cancellation(const fraction f);
/**
 * Compute the greatest common divisor based on the euclidean
 * algorithm.
 */
int gcd(const int num, const int den);

int main(int argc, char **argv) {
	// setup the bad fraction for later.
	bad.den = 0;
	bad.num = 0;
	// initalize and proceed.
	vector<fraction> fractions;
	cout << "finding fractions.." << endl;
	for (int den = 10; den < 100; den++)
		for (int num = 10; num < den; num++) {
			fraction f;
			f.den = den;
			f.num = num;
			fraction result = incorrect_cancellation(f);
			// check for an invalid fraction.
			if (result.den == bad.den && result.num == bad.num)
				continue;
			else {
				cout << f.num << " / " << f.den << " == " << result.num
						<< " / " << result.den << endl;
				fractions.push_back(f);
			}
		}
	cout << "found " << fractions.size() << " fractions" << endl;
	cout << "multiplying fractions and running euclid's algorithm (gcd).."
			<< endl;
	// multiply the fractions until the vector contains 1 element.
	while (fractions.size() > 1) {
		// get 2 fractions
		fraction f1 = fractions[0];
		fraction f2 = fractions[1];
		// remove them from the vector.
		fractions.erase(fractions.begin());
		fractions.erase(fractions.begin());
		// multiply the result into f1.
		cout << f1.num << "/" << f1.den << " * " << f2.num << "/" << f2.den
				<< flush;
		f1.den *= f2.den;
		f1.num *= f2.num;
		cout << " <=> " << f1.num << "/" << f1.den << flush;
		// run euclid to avoid int overflows in the long run.
		int _gcd = gcd(f1.num, f1.den);
		f1.num /= _gcd;
		f1.den /= _gcd;
		cout << " <=> " << f1.num << "/" << f1.den << endl;
		// insert the new merged fraction and proceed.
		fractions.push_back(f1);
	}
	// print the last element on the vector.
	cout << "The end fraction is: " << fractions[0].num << "/"
			<< fractions[0].den << endl;
}

fraction incorrect_cancellation(const fraction f) {
	// check to remove the 10-digit in the denominator and the 1-digit
	// nominator.
	if (f.den / 10 == f.num % 10) {
		fraction tmp;
		tmp.den = f.den % 10;
		tmp.num = f.num / 10;
		if (((double) f.num) / ((double) f.den) == ((double) tmp.num)
				/ ((double) tmp.den))
			return tmp;
	}
	if (f.den % 10 == f.num / 10) {
		fraction tmp;
		tmp.den = f.den / 10;
		tmp.num = f.num % 10;
		if (((double) f.num) / ((double) f.den) == ((double) tmp.num)
				/ ((double) tmp.den))
			return tmp;
	}
	return bad;
}

int gcd(int num, int den) {
	if (num == 0)
		return den;
	while (den != 0)
		if (num > den)
			num -= den;
		else
			den -= num;
	return num;
}
