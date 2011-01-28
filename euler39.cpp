/*
 * euler39.cpp
 *
 *  Created on: 25/01/2011
 *      Author: Dennis Hedegaard
 */

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cassert>
#include <ctime>

using namespace std;

// checks to see if the triangle is right angeled or not.
bool is_right_angeled(int a, int b, int c);
// some tests for functionality.
void test();

int main() {
	int result[1000];
	for (int i = 0; i < 1000; i++)
		result[i] = 0;
	cout << "testing.. " << flush;
	test();
	cout << "done" << endl;
	cout << "running.. " << flush;
	for (int b = 1; b <= 1000; b++)
		for (int a = 0; a <= b; a++)
			for (int c = 0; c <= 1000; c++) {
				int p = a + b + c;
				if (p <= 1000 && is_right_angeled(a, b, c))
					result[p]++;
			}
	cout << "done" << endl;
	cout << "finding maximum count.. " << flush;
	int maxp = 1, maxcount = 0;
	for (int i = 0; i < 1000; i++)
		if (result[i] > maxcount) {
			maxcount = result[i];
			maxp = i;
		}
	cout << "done, maximum count is: " << maxcount << " for p value " << maxp
			<< endl;
	return 0;
}

void test() {
	assert(is_right_angeled(3, 4,5));
	assert(!is_right_angeled(3, 4,6));
	assert(is_right_angeled(20,48,52));
	assert(is_right_angeled(24,45,51));
	assert(is_right_angeled(30,40,50));
}

// implemented using pythagoras
inline bool is_right_angeled(int a, int b, int c) {
	return c * c == a * a + b * b;
}
