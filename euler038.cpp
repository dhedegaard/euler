/*
 * euler38.cpp
 *
 *  Created on: 20/02/2011
 *      Author: Dennis Hedegaard
 */

#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>

using namespace std;

static void initialize_bitvector(vector<bool> &v);
/**
 * Checks the integer to see if it can form a pandigital number
 * by the use of multiplying the number from 1 to n and con-
 * catenating the number into a pandigital number 1-9.
 */
static long long check_integer(int num);
/**
 * Splits the number num into single digit numbers, then adds it to
 * the set if able.
 *
 * @returns -1 if false, else the pandigital number.
 */
static bool split_and_add(vector<bool> &s, int num);
static bool contains_pandigital(const vector<bool> &s);

int main(int argc, char **argv) {
	assert(check_integer(192) == 192384576);
	long long max = 0;
	for (int i = 1; i < 9999; i++) {
		long long l = check_integer(i);
		if (l != -1 && l > max)
			max = l;
	}
	cout << max << endl;
	return 0;
}

static long long check_integer(int num) {
	vector<bool> pandigits;
	initialize_bitvector(pandigits);
	long long result = 0;
	for (int n = 1;; n++) {
		int tmp = num * n;
		// check to see if we've hit a digit more than once, if
		// not mark the new digits in the bitvector.
		if (!split_and_add(pandigits, tmp))
			return -1;
		// get the number of digits in tmp.
		result = result * pow(10, ((int) log10(tmp) + 1)) + tmp;
		if (contains_pandigital(pandigits)) {
			if (n == 1) // n in n > 1
				return -1;
			else
				break;
		}
	}
	return result;
}

static bool split_and_add(vector<bool> &s, int num) {
	while (num > 0) {
		int tmp = num % 10;
		if (tmp == 0 || s[tmp]) // escape on 0 or marked number.
			return false;
		else
			s[tmp] = true;
		num /= 10;
	}
	return true;
}

static bool contains_pandigital(const vector<bool> &s) {
	if (s.size() != 10)
		throw "bit vector size not 10.";
	for (vector<bool>::const_iterator ite = s.begin() + 1; ite != s.end(); ite++)
		if (!*ite)
			return false;
	return true;
}

static void initialize_bitvector(vector<bool> &v) {
	while (v.size() < 10)
		v.push_back(false);
}
