/*
 * euler057.cpp
 *
 *  Created on: 18/03/2011
 *      Author: Dennis Hedegaard
 */

#include <iostream>
#include <gmpxx.h>

using namespace std;

int main(int argc, char **argv) {
	mpz_class num[2], den[2];
	// add first iteration (3/2)
	num[0] = 3;
	den[0] = 2;
	// add second iteration (7/5)
	num[1] = 7;
	den[1] = 5;
	int i = 0;
	int count = 0;
	for (int exp = 3; exp <= 1000; exp++) {
		// N_i = (2*N_i-1) + N_i-2 for i ≥ 3
		num[i] = (2 * num[(i + 1) % 2]) + num[i];
		// D_i = (2*D_i-1) + D_i-2 for i ≥ 3
		den[i] = (2 * den[(i + 1) % 2]) + den[i];
		if (num[i % 2].get_str(10).size() > den[i % 2].get_str(10).size())
			count++;
		i = (i + 1) % 2; // switch 0->1 and 1->0
	}
	cout << count << endl;
	return 0;
}
