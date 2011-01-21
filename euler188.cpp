/*
 * euler188.cpp
 *
 *  Created on: 21/01/2011
 *      Author: Dennis Hedegaard
 */

#include <iostream>
#include <iomanip>
#include <cassert>
#include <ctime>
// remember to link to gmp and gmpxx
#include <gmpxx.h>

using namespace std;

// Gets 8 numbers of digits, when used with a modulo operation.
#define DIGITS 100000000

/**
 * This function does hyperexponentiation, it however only returns the first 8 digits.
 *
 */
mpz_class hyperexp(const int a, const unsigned b);
void test();

int main() {
	test();
	cout << "Now, look for the pattern (i only calculate the first 8 digits):";
	for (int i = 1; i <= 1855; i++) {
		time_t start = time(NULL);
		cout << "(1855^^" << i << "): " << hyperexp(1777, i) << endl;
		cout << "took " << difftime(time(NULL), start) << " seconds." << endl;
	}
	return 0;
}

mpz_class hyperexp(const int a, const unsigned b) {
	if (b == 0)
		throw "b should never be 0.";
	if (b == 1)
		return a;
	else {
		// The cap is essentially the exponent, in this case it's done recursively.
		mpz_class cap = hyperexp(a, b - 1);
		// variable containing the result
		mpz_class result(1);
		// variables used for fast iterations.
		mpz_class _100_a(1), _10k_a(1);
		// first we calculate variables used for fast iterations. This will speed things up ALOT.
		for (unsigned i = 1; i <= 100; i++) // 100
			_100_a *= a;
		for (unsigned i = 1; i <= 100; i++) // 10k
			_10k_a *= _100_a;
		// iterations on 10k's.
		for (unsigned i = 1; i <= cap / 10000; i++)
			result = (result * _10k_a) % DIGITS;
		// iterations on 100's
		for (unsigned i = 1; i <= (cap % 10000) / 100; i++)
			result = (result * _100_a) % DIGITS;
		// iterations on 1's.
		for (unsigned i = 1; i <= cap % 100; i++)
			result = (result * a) % DIGITS;
		return result;
	}
}
void test() {
	cout << "running selftests.. " << flush;
	assert(hyperexp(3, 2) == 27); // 3**3**3 == 3**9 == 27
	assert(hyperexp(3, 3) == 97484987); // last 8 digits (97484987) of 7625597484987
	cout << "done, functionality seems alright." << endl;
}
