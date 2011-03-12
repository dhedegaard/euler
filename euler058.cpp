/*
 * euler58.cpp
 *
 *  Created on: 29/01/2011
 *      Author: Dennis Hedegaard
 */

#include <iostream>
#include <cmath>

using namespace std;

static bool is_prime(const int);

int main() {
	int primecount = 0; // hold the primal count
	int diagonals = 0; // holds the total number of diagonals encounteret
	/* the stage of the iteration, 0,1,2,3 cyclic.
	 * Start before stage 0 since the first square if 1 still increments by 2.
	 */
	int stage = -1;
	/*
	 * the current incremental value. Starts at 2, since that's the distance from
	 * the center to the top right of a 1x1 -> 3x3 square.
	 */
	int incremental = 2;
	int num = 1; // the current number of the diagonal.
	while (true) {
		if (stage == 3) { // check for wrapping stage
			double pct = ((double) primecount) / ((double) diagonals) * 100;
			if (incremental % 1000 == 0)
				cout << incremental + 1 << "x" << incremental - 1 << " has "
						<< diagonals << " diagonals and " << primecount
						<< " of those are primes. (" << pct << "%) num: "
						<< num << endl;
			if (pct < 10)
				break;
			incremental += 2; // increase the incremental value, since the width of the square increases.
		}
		// increase counters.
		if (is_prime(num))
			primecount++;
		num += incremental;
		stage = (stage + 1) % 4; // increment/wrap stage
		diagonals++;
	}
	cout << "the resulting square width is " << incremental - 1 << endl;
	return 0;
}

static bool is_prime(const int num) {
	if (num < 2)
		return false;
	// run until half the number to check, since that's where % 2 starts.
	int cap = sqrt(num);
	for (int i = 3; i <= cap; i += 2)
		if (num % i == 0)
			return false;
	return true;
}
