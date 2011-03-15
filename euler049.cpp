/*
 * euler049.cpp
 *
 *  Created on: 15/03/2011
 *      Author: Dennis Hedegaard
 */

#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

static set<int> generate_primes(int cap);

static vector<int> convert_to_arr(int a);

int main(int argc, char **argv) {
	set<int> primes = generate_primes(9999);
	// remove primes with less than 4 digits.
	for (set<int>::iterator ite = primes.begin(); *ite < 1000 && ite
			!= primes.end(); ite++)
		primes.erase(ite);
	// iterate and check
	for (set<int>::iterator ite1 = primes.begin(); ite1 != primes.end(); ite1++) {
		vector<int> digits1 = convert_to_arr(*ite1);
		for (set<int>::iterator ite2 = ite1; ite2 != primes.end(); ite2++) {
			vector<int> digits2 = convert_to_arr(*ite2);
			if (digits1 != digits2)
				continue;
			int diff = *ite2 - *ite1;
			if (diff == 0)
				continue;
			set<int>::iterator ite3 = primes.find(*ite2 + diff);
			if (ite3 == primes.end())
				continue;
			vector<int> digits3 = convert_to_arr(*ite3);
			if (digits1 != digits3)
				continue;
			cout << *ite1 << " - " << *ite2 << " - " << *ite3 << " (" << diff
					<< ")" << endl;
		}
	}
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

static vector<int> convert_to_arr(int a) {
	vector<int> v;
	while (a > 0) {
		v.push_back(a % 10);
		a /= 10;
	}
	sort(v.begin(), v.end());
	return v;
}
