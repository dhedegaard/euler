/*
 * euler44.cpp
 *
 *  Created on: 22/02/2011
 *      Author: Dennis Hedegaard
 */

#include <iostream>
#include <set>
#include <cmath>
#include <cassert>

using namespace std;

/**
 * This function generates the pentagonal value for a value n.
 * The implementation uses the oentagonal number formula.
 */
static long get_pentagonal(const int n);
/**
 * Checks to see if a number is pentagonal, this is done by
 * isolating n in the formula in get_pentagonal(int).
 */
static bool is_pentagonal(const int num);

int main(int argc, char **argv) {
	// check is_pentagonal
	assert(is_pentagonal(1));
	assert(is_pentagonal(5));
	assert(is_pentagonal(12));
	assert(is_pentagonal(22));
	assert(!is_pentagonal(2));
	assert(!is_pentagonal(4));
	assert(!is_pentagonal(13));
	assert(!is_pentagonal(21));
	// check get_pentagonal
	assert(get_pentagonal(1) == 1);
	assert(get_pentagonal(2) == 5);
	assert(get_pentagonal(3) == 12);
	assert(get_pentagonal(4) == 22);
	assert(get_pentagonal(5) == 35);
	assert(get_pentagonal(6) == 51);
	assert(get_pentagonal(7) == 70);
	assert(get_pentagonal(8) == 92);
	// the set containing D, which is |p_j - p_k|.
	set<int> s;
	for (int np = 1; np < 3000; np++) {
		long p = get_pentagonal(np);
		for (int nq = 1; nq < 3000; nq++) {
			if (np < nq || np == nq)
				continue;
			long q = get_pentagonal(nq);
			if (is_pentagonal(p + q)) {
				int tmp = p > q ? p - q : q - p;
				if (is_pentagonal(tmp)) {
					s.insert(tmp);
					cout << "found |p-q|: " << tmp << " from p: " << p
							<< " and q: " << q << endl;
				}
			}
		}
	}
	// if we found one, print the first one. Since it's the smallest D.
	if (s.size() > 0)
		cout << "the smallest D found is " << *s.begin() << endl;
	else
		cout << "unable to find a sollution." << endl;
	return 0;
}

static long get_pentagonal(const int n) {
	// uses the base formula for generating a pentagonal number
	// based on the formula specified on the euler site.
	return n * (3 * n - 1) / 2;
}

static bool is_pentagonal(const int p) {
	// Since pentagon number is p=n(3n-1)/2, we isolate n.
	// n = (sqrt(24p+1)+1)/6 - This is used for checking the number.
	double n = (sqrt(24 * p + 1) + 1) / 6;
	// check that the number is equal to the floored double.
	return n == floor(n);
}
