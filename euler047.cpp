/*
 * euler047.cpp
 *
 *  Created on: 15/03/2011
 *      Author: Dennis Hedegaard
 */

#include <iostream>
#include <map>
#include <iomanip>
#include <cassert>

using namespace std;

static map<int, int> get_prime_factors(int i);

int main(int argc, char **argv) {
	map<int, int> primes;
	// START testing
	cout << "testing.. " << flush;
	// test 14 => 2 x 7
	primes = get_prime_factors(14);
	assert(primes.size() == 2);
	assert(primes.find(2)->second == 1);
	assert(primes.find(7)->second == 1);
	// test 15 => 3 x 5
	primes = get_prime_factors(15);
	assert(primes.size() == 2);
	assert(primes.find(3)->second == 1);
	assert(primes.find(5)->second == 1);
	// test 644 => 2^2x7x23
	primes = get_prime_factors(644);
	assert(primes.size() == 3);
	assert(primes.find(2)->second == 2);
	assert(primes.find(7)->second == 1);
	assert(primes.find(23)->second == 1);
	// test 645 => 3x5x43
	primes = get_prime_factors(645);
	assert(primes.size() == 3);
	assert(primes.find(3)->second == 1);
	assert(primes.find(5)->second == 1);
	assert(primes.find(43)->second == 1);
	// test 646 => 2x17x19
	primes = get_prime_factors(646);
	assert(primes.size() == 3);
	assert(primes.find(2)->second == 1);
	assert(primes.find(17)->second == 1);
	assert(primes.find(19)->second == 1);
	cout << "done!" << endl;
	// END testing
	int count = 0;
	for (int i = 650;; i++) {
		primes = get_prime_factors(i);
		if (primes.size() == 4)
			count++;
		else
			count = 0;
		if (count == 4) {
			cout << i + 1 - count << endl;
			break;
		}
	}
	return 0;
}

static map<int, int> get_prime_factors(int n) {
	map<int, int> prime_factors;
	for (int i = 2; i <= n; i++) {
		int count = 0;
		while (n % i == 0) {
			count++;
			n /= i;
		}
		if (count > 0)
			prime_factors.insert(pair<int, int> (i, count));
	}
	if (n > 1)
		prime_factors.insert(pair<int, int> (n, 1));
	return prime_factors;
}
