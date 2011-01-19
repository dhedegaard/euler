/*
 * euler45.cpp
 *
 *  Created on: 19/01/2011
 *      Author: Dennis Hedegaard
 */

#include <iostream>

using namespace std;

long long next_triangle();
long long next_pentagonal();
long long next_hexagonal();

int main(int argc, char **argv) {
	long long triangle = next_triangle(), pentagonal = next_pentagonal(),
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

long long next_triangle() {
	static long i = 2;
	long long tmp = i;
	tmp += (long long) 1;
	tmp *= (long long) i;
	tmp /= (long long) 2;
	i++;
	return tmp;
}

long long next_pentagonal() {
	static long i = 2;
	long long tmp = i;
	tmp *= (long long) 3;
	tmp -= (long long) 1;
	tmp *= (long long) i;
	tmp /= (long long) 2;
	i++;
	return tmp;
}

long long next_hexagonal() {
	static long i = 2;
	long long tmp = i;
	tmp *= (long long) 2;
	tmp -= (long long) 1;
	tmp *= (long long) i;
	i++;
	return tmp;
}
