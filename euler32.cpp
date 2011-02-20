/*
 * euler32.cpp
 *
 *  Created on: 20/02/2011
 *      Author: Dennis Hedegaard
 */

#include <iostream>
#include <vector>
#include <cassert>
#include <set>
#include <cmath>

using namespace std;

/**
 * Return an intialized bitvector with 9 false.
 */
static vector<bool> initialize_bitvector();
/**
 * Return the pandigital product of a and b, only if
 * all 3 numbers are pandigital 1..9., else -1.
 */
static int pandigital_product(int a, int b);
/**
 * Checks to see if the number supplied is valid in the
 * bitvector, the digits will get marked in the vector.
 *
 * @return true if all the digits are previously false in
 * 		the vector, else false.
 */
static bool valid_number(vector<bool> &bv, int num);

int main(int argc, char **argv) {
	assert(pandigital_product(39, 186) == 7254);
	assert(pandigital_product(39, 185) == -1);
	set<int> products;
	for (int a = 1; a < 10000; a++) {
		for (int b = 1; b < a && a * b < 10000; b++) {
			int c = pandigital_product(a, b);
			if (c == -1)
				continue;
			if (products.find(c) == products.end())
				products.insert(c);
		}
	}
	int sum = 0;
	for (set<int>::iterator ite = products.begin(); ite != products.end(); ite++)
		sum += *ite;
	cout << sum << endl;
	return 0;
}

int pandigital_product(int a, int b) {
	vector<bool> bitv = initialize_bitvector();
	if (!valid_number(bitv, a))
		return -1;
	if (!valid_number(bitv, b))
		return -1;
	int c = a * b;
	if (!valid_number(bitv, c))
		return -1;
	for (vector<bool>::iterator ite = bitv.begin(); ite != bitv.end(); ite++)
		if (!*ite)
			return -1;
	return c;

}

vector<bool> initialize_bitvector() {
	vector<bool> result;
	while (result.size() < 9)
		result.push_back(false);
	return result;
}

bool valid_number(vector<bool> &bv, int num) {
	while (num > 0) {
		int tmp = num % 10;
		if (tmp == 0)
			return false;
		if (bv[tmp - 1])
			return false;
		else
			bv[tmp - 1] = true;
		num /= 10;
	}
	return true;
}
