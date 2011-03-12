/*
 * euler55.cpp
 *
 *  Created on: 28/01/2011
 *      Author: Dennis Hedegaard
 */

#include <iostream>
#include <iomanip>
#include <sstream>
#include <cassert>
#include <gmpxx.h>

using namespace std;

// a function that checks an integer, to see if it's a palindrome or not.
static bool is_palindrome(const mpz_class a);
// checks to see if you hit a lychrel number, gives up after 50 iterations.
static bool is_lychrel(const mpz_class a);
// implements a way of reversing a number.
static mpz_class reverse_int(const mpz_class a);

int main() {
	// assertions
	cout << "testing.. " << flush;
	assert(is_palindrome(1234321));
	assert(!is_palindrome(123432));
	assert(!is_palindrome(23454321));
	cout << "done" << endl;
	int count = 0;
	for (int i = 1; i < 10000; i++)
		if (is_lychrel(i))
			count++;
	cout << "found " << count << " numbers." << endl;
	return 0;
}

static bool is_palindrome(const mpz_class a) {
	ostringstream stream;
	stream << a;
	string s = stream.str();
	string::size_type len = s.size();
	for (string::size_type i = 0; i < len / 2; i++)
		if (s[i] != s[len - i - 1])
			return false;
	return true;
}

static bool is_lychrel(mpz_class a) {
	for (int i = 0; i < 50; i++) { // iterate 50 iterations.
		a = a + reverse_int(a); // reverse and add
		if (is_palindrome(a)) // check for palindrome
			return false;
	}
	return true;
}

// reverse by using modulus, and appending to another number.
static mpz_class reverse_int(mpz_class a) {
	static mpz_class gmp_ten("10");
	mpz_class result = 0;
	while (a != 0) {
		mpz_class d = a % gmp_ten;
		result = (result * gmp_ten) + d;
		a /= 10;
	}
	return result;
}
