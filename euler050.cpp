/*
 * euler50.cpp
 *
 *  Created on: 20/02/2011
 *      Author: Dennis Hedegaard
 */

#include <iostream>
#include <iomanip>
#include <set>
#include <cmath>

#define CAP 1000000

using namespace std;

static set<int> generate_primes(int cap);

int main(int argc, char **argv) {
	cout << "generating primes up to " << CAP << ".. " << flush;
	set<int> primes = generate_primes(CAP);
	cout << "done " << primes.size() << " generated." << endl;
	int maxsum = 0;
	int maxcount = 0;
	for (set<int>::iterator start = primes.begin(); start != primes.end(); start++) {
		int sum = 0;
		int count = 0;
		for (set<int>::iterator delta = start; delta != primes.end(); delta++) {
			if (primes.find(sum) != primes.end() && sum < CAP) {
				if (count > maxcount) {
					maxcount = count;
					maxsum = sum;
				}
			}
			if (sum + *delta > CAP)
				break;
			sum += *delta;
			count++;
		}
	}
	cout << maxcount << ": " << maxsum << endl;
	return 0;
}

/**
 * Implemented using the sieve of eratosthenes.
 */
static set<int> generate_primes(int cap) {
	// should end up containing the result
	set<int> result;
	// a bit array for all the numbers sieved.
	bool sieved[cap];
	for (int i = 0; i < cap; i++)
		sieved[i] = false;
	// the first two are marked (0 and 1, since we start at 2).
	sieved[0] = true;
	sieved[1] = true;
	// iterate and sieve on the bit array
	for (int i = 2; i <= cap; i++) {
		if (sieved[i])
			continue;
		result.insert(i);
		for (int j = i; j <= cap; j += i)
			if (!sieved[j])
				sieved[j] = true;
	}
	return result;
}
