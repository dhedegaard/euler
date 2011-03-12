/*
 * euler97.cpp
 *
 *  Created on: 21/01/2011
 *      Author: Dennis Hedegaard
 */

#include <iostream>
// remember to link gmp and gmpxx
#include <gmpxx.h>

// modulus value, for 10 digits.
#define NUMCOUNT 10000000000L

using namespace std;

/**
 * Used for finding the power of a 2 ** power, this only returns the last
 * 10 digits of the actual number for performance reasons.
 */
mpz_class power2(const unsigned power);

int main() {
	mpz_class result = power2(7830457);
	result = (result * 28433 + 1) % NUMCOUNT;
	cout << result << endl;
	return 0;
}

mpz_class power2(const unsigned _power) {
	// calculating 2 ** 100
	mpz_class _2_in_100(1);
	for (int i = 1; i <= 100; i++)
		_2_in_100 *= 2;
	// running all above 100
	mpz_class result(1);
	for (unsigned i = 1; i <= _power / 100; i++)
		result = (result * _2_in_100) % NUMCOUNT;
	// running remains
	for (unsigned i = 1; i <= _power % 100; i++)
		result = (result * 2) % NUMCOUNT;
	return result;
}
