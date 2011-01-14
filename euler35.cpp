/*
 * euler35.cpp
 *
 *  Created on: 14/01/2011
 *      Author: Dennis Hedegaard
 */

#include <iostream>
#include <iomanip>
#include <vector>
#include <sstream>
#include <cstdlib>	// itoa()
#include <algorithm> // reverse algorithm for vector iterator

using namespace std;

/**
 * Attempts to find all the circular primes between 1 and cap. Returns the number of primes found.
 */
int find_circular_primes(unsigned cap);

/**
 * Checks by the use of some method to see if the argument is a prime.
 */
bool is_prime(unsigned);
/**
 * Checks to see if the argument is a "circular prime".
 */
bool is_circular_prime(unsigned);
/**
 * Assembles all the integers in the vector and checks to see if all the permutations are primes.
 */
bool assemble_and_check(vector<int> &);

int main() {
	int hundreds = find_circular_primes(100);
	if (hundreds == 13)
		cout << "number of circular primes below 100 is " << hundreds << endl;
	else {
		cerr << "number of circular primes below 100 is not 13, exiting" << endl;
		return 1;
	}
	cout << "calculating for 1 mio, this might take a while.." << endl;
	int count = find_circular_primes(1000000);
	cout << "found " << count << " circular primes below 1 mio :)" << endl;
	return 0;
}

int find_circular_primes(unsigned cap) {
	int count = 0;
	for (unsigned i = 2; i < cap; i++) {
		bool b;
		if (i < 10)
			b = is_prime(i);
		else
			b = is_circular_prime(i);
		if (b) {
			count++;
		}
	}
	return count;
}

bool is_prime(unsigned num) {
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

bool is_circular_prime(unsigned num) {
	// read the number into a string
	ostringstream stream;
	stream << num;
	// put the integers into a vector
	vector<int> v;
	int i = atoi(stream.str().c_str());
	while (i > 0) {
		if (i > 9) {
			int _i = i % 10;
			i /= 10;
			v.push_back(_i);
		} else {
			v.push_back(i);
			i = 0;
		}
	}
	/* check for even numbers, we there's any even numbers or 5 in the vector,
	 * some permutations cannot be prime numbers since the even number or 5 would
	 * eventually be at the ones position. */
	for (vector<int>::iterator ite = v.begin(); ite != v.end(); ite++)
		if (*ite % 2 == 0 || *ite == 5)
			return false;
	// Reverse the vector, since the numbers got inserted in the wrong order (one's positions at the front).
	reverse(v.begin(), v.end());
	// get the size for better allocating vectors in the iterations.
	vector<int>::size_type v_size = v.size();
	// iterate on all the possible circulars by pushing an iterator through the outer vector.
	for (vector<int>::iterator pos = v.begin(); pos != v.end(); pos++) {
		// assemble an internal vector, starting from the outer iterator to the end, ending from beginning to just before the iterator.
		vector<int> arr(v_size);
		int i = 0;
		// copy from pos to end exclusive.
		for (vector<int>::iterator _pos = pos; _pos != v.end(); _pos++)
			arr[i++] = *_pos;
		// copy from begin to pos exclusive.
		for (vector<int>::iterator _pos = v.begin(); _pos != pos; _pos++)
			arr[i++] = *_pos;
		// Check the number and return false, if it's not a prime number.
		if (!assemble_and_check(arr))
			return false;
	}
	// the number should be a
	return true;
}

bool assemble_and_check(vector<int> &v) {
	// avoid all numbers starting with 0. Means we "accept" them.
	if (v[0] == 0)
		return true;
	// assemble the number by iterating the vector and multiply the number by 10 before each new number.
	int num = 0;
	vector<int>::iterator ite = v.begin();
	while (ite != v.end())
		num = num * 10 + *ite++;
	// check for prime
	return is_prime(num);
}
