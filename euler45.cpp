/*
 * euler45.cpp
 *
 *  Created on: 19/01/2011
 *      Author: Dennis Hedegaard
 */

#include <iostream>
#include <gmpxx.h>

using namespace std;

mpz_class next_triangle();
mpz_class next_pentagonal();
mpz_class next_hexagonal();

int main(int argc, char **argv) {
	mpz_class triangle = next_triangle(), pentagonal = next_pentagonal(),
			hexagonal = next_hexagonal();
	while (true) {
		if (triangle < pentagonal || triangle < hexagonal)
			triangle = next_triangle();
		else if (pentagonal < triangle || pentagonal < hexagonal)
			pentagonal = next_pentagonal();
		else if (hexagonal < triangle || hexagonal < pentagonal)
			hexagonal = next_hexagonal();
		else if (triangle == 40755)
			triangle = next_triangle();
		else {
			cout << triangle << endl;
			return 0;
		}
	}
}

mpz_class next_triangle() {
	static long i = 2;
	mpz_class tmp(i);
	tmp += 1;
	tmp *= i;
	tmp /= 2;
	i++;
	return tmp;
}

mpz_class next_pentagonal() {
	static long i = 2;
	mpz_class tmp(i);
	tmp *= 3;
	tmp -= 1;
	tmp *= i;
	tmp /= 2;
	i++;
	return tmp;
}

mpz_class next_hexagonal() {
	static long i = 2;
	mpz_class tmp(i);
	tmp *= 2;
	tmp -= 1;
	tmp *= i;
	i++;
	return tmp;
}
