/*
 * euler145.cpp
 *
 *  Created on: 01/03/2011
 *      Author: Dennis Hedegaard
 */

#include <iostream>
#include <gmpxx.h>

using namespace std;

#define DEBUG 0

static mpz_class reverse(mpz_class n);
static bool consists_odd(mpz_class n);
static bool is_reversible(mpz_class i);

int main(int argc, char **argv) {
	int count = 0;
	for (int i = 1; i < 1000000000; i++) {
		if (is_reversible(i))
			count++;
	}
	cout << count << endl;
	return 0;
}

static bool is_reversible(mpz_class i) {
	if (i % 10 == 0) // skip leader zeros
		return false;
	mpz_class rev = reverse(i);
	if (rev == -1) // skip leading zeros in reverse
		return false;
	mpz_class sum = i + rev;
	// check for odd decimal sum
	if (consists_odd(sum)) {
		if (DEBUG)
			cout << i << " + " << rev << " = " << sum << endl;
		return true;
	}
	else
		return false;
}

static bool consists_odd(mpz_class n) {
	while (n > 0) {
		if ((n % 10) % 2 == 0)
			return false;
		n /= 10;
	}
	return true;
}

static mpz_class reverse(mpz_class n) {
	// avoid leading zeros.
	if (n % 10 == 0)
		return -1;
	mpz_class result = 0;
	// iterate and return
	while (n > 0) {
		result = result * 10 + (n % 10);
		n /= 10;
	}
	return result;
}
