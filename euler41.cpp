/*
 * euler41.cpp
 *
 *  Created on: 15/01/2011
 *      Author: Dennis Hedegaard
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

/**
 * same as euler35.cpp
 */
bool is_prime(const unsigned&);

int assemble_number_from_vector(const vector<unsigned> &v);

bool test(unsigned&);

int main() {
	// run for 9 pandigitals towards 1.
	for (unsigned i = 9; i > 0; i--)
		if (test(i))
			return 0;
}

bool test(unsigned &num) {
	vector<unsigned> v;
	// fill the vector
	for (unsigned i = 1; i <= num; i++)
		v.push_back(i);
	// reverse-sort the vector, since we only need the highest n-pandigital prime.
	sort(v.rbegin(), v.rend());
	// check the base case, before we permutate.
	if (is_prime(assemble_number_from_vector(v))) {
		cout << assemble_number_from_vector(v);
		return true;
	}
	// run permutations until a prime is encountered.
	while (prev_permutation(v.begin(), v.end())) {
		if (is_prime(assemble_number_from_vector(v))) {
			cout << assemble_number_from_vector(v);
			return true;
		}
	}
	// we didn't hit a prime, let's iterate on the pandigital n-digit.
	return false;
}

int assemble_number_from_vector(const vector<unsigned> &v) {
	int num = 0;
	for (vector<unsigned>::const_iterator ite = v.begin(); ite != v.end(); ite++)
		num = num * 10 + *ite;
	return num;
}

bool is_prime(const unsigned &num) {
	if (num < 2)
		return false;
	if (num == 2)
		return true;
	// all even numbers (except 2) aint primes.
	if (num % 2 == 0)
		return false;
	// run until half the number to check, since that's where % 2 starts.
	for (unsigned i = 2; i <= num / 2; i++)
		if (num % i == 0)
			return false;
	return true;
}
