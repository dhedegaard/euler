/*
 * euler40.cpp
 *
 *  Created on: 19/01/2011
 *      Author: Dennis Hedegaard
 */

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main() {
	string buffer;
	int i = 1;
	while (buffer.size() < 1000000) {
		ostringstream stream;
		stream << i++;
		buffer += stream.str();
	}
	int result = 1;
	// Fill a vector with the positions we need.
	vector<int> ns;
	ns.push_back(1);
	ns.push_back(10);
	ns.push_back(100);
	ns.push_back(1000);
	ns.push_back(10000);
	ns.push_back(100000);
	ns.push_back(1000000);
	// iterate and multiply the values onto result.
	for (vector<int>::iterator ite = ns.begin(); ite != ns.end(); ite++) {
		char c = buffer[*ite - 1];
		result *= c - '0';
	}
	cout << result << endl;
	return 0;
}

