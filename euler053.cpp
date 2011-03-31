/*
 * euler053.cpp
 *
 *  Created on: 31/03/2011
 *      Author: Dennis Hedegaard
 */

#include <iostream>
#include <gmpxx.h>

using namespace std;

static mpz_class factorial(int x) {
	mpz_class result = 1;
	while (x > 1)
		result *= x--;
	return result;
}

static mpz_class calc(int n, int r) {
	return factorial(n) / (factorial(r) * factorial(n - r));
}

int main(int argc, char **argv) {
	int count = 0, i, j;
	for (i = 1; i <= 100; i++)
		for (j = 1; j < i; j++) {
			mpz_class _calc = calc(i, j);
			if (_calc > 1000000)
				count++;
			cout << i << ", " << j << " = " << _calc << "\n";
		}
	cout << "count: " << count << "\n";
	return 0;
}
