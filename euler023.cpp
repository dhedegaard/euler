/*
 * euler23.cpp
 *
 *  Created on: 15/01/2011
 *      Author: Dennis Hedegaard
 */

/**
 * Calculates the sum of the proper divisors for the number specified.
 */
#include <iostream>
#include <set>
#include <cassert>

using namespace std;

static int sum_of_proper_divisors(const int);

static void generate_abundant_numbers(const int cap, set<int> &v);

int main() {
	assert(28 == sum_of_proper_divisors(28)); // check to see if 28 is a perfect number
	set<int> v;
	for (int i = 1; i <= 28123; i++)
		v.insert(i);
	set<int> abundant_numbers;
	cout << "generating abundant numbers." << endl;
	generate_abundant_numbers(28123, abundant_numbers);
	cout << "generated " << abundant_numbers.size()
			<< " abundant numbers into a set." << endl;
	cout
			<< "removing numbers being the sum of 2 abundant numbers. It will take some time."
			<< endl;
	for (set<int>::iterator i = abundant_numbers.begin(); i
			!= abundant_numbers.end(); i++)
		for (set<int>::iterator j = i; j != abundant_numbers.end(); ++j)
			v.erase(*j + *i);
	cout << "all done. " << v.size() << " numbers left, generating sum." << endl;
	int sum = 0;
	for (set<int>::iterator ite = v.begin(); ite != v.end(); ite++)
		sum += *ite;
	cout << "sum: " << sum << endl;
}

static int sum_of_proper_divisors(const int num) {
	int sum = 0;
	for (int i = 1; i <= num / 2; i++)
		if (num % i == 0)
			sum += i;
	return sum;
}

static void generate_abundant_numbers(const int cap, set<int> &v) {
	for (int i = 1; i <= cap; i++)
		if (sum_of_proper_divisors(i) > i)
			v.insert(i);
}
