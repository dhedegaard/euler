/*
 * euler099.cpp
 *
 *  Created on: 19/08/2011
 *      Author: Dennis Hedegaard
 */

#include <iostream>
#include <fstream>
#include <cmath>

#define DATA "euler099-data"

using namespace std;

int main(int argc, char **argv) {
	unsigned max = 0;
	int linenum = -1;
	ifstream in(DATA);
	char ch;
	unsigned base, expo;
	int curline = 1;
	while (in.good()) {
		in >> base >> ch >> expo;
		// base^expo is relative to expo*log(base)
		unsigned val = expo * log(static_cast<double>(base));
		if (val > max) {
			max = val;
			linenum = curline;
			cout << "new max: " << curline << ": " << base << "^" << expo
					<< endl;
		}
		curline++;
	}
	cout << "-------------------------" << endl;
	cout << "max is at line " << linenum << endl;
	return 0;
}
