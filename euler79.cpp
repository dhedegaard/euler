/*
 * euler79.cpp
 *
 *  Created on: 24/01/2011
 *      Author: Dennis Hedegaard
 */

#include <iostream>
#include <fstream>
#include <set>
#include <map>

using namespace std;

#define DATA "euler79-data"

struct {
	set<char> before;
	set<char> after;
	char num;
}typedef number;

int main() {
	ifstream str(DATA);
	string s;
	map<char, number> m;
	while (str >> s) {
		char c1 = s[0];
		char c2 = s[1];
		char c3 = s[2];
		number n1, n2, n3;
		// get or create (on the stack) the first number.
		if (m.find(c1) == m.end())
			n1.num = c1;
		else
			n1 = m.at(c1);
		// get or create (on the stack) the second number.
		if (m.find(c2) == m.end())
			n2.num = c2;
		else
			n2 = m.at(c2);
		// get or create (on the stack) the third number.
		if (m.find(c3) == m.end())
			n3.num = c3;
		else
			n3 = m.at(c3);
		// c1
		n1.after.insert(c2);
		n1.after.insert(c3);
		// c2
		n2.before.insert(c1);
		n2.after.insert(c3);
		// c3
		n3.before.insert(c1);
		n3.before.insert(c2);
		// make sure that we can insert the keys.
		m.erase(c1);
		m.erase(c2);
		m.erase(c3);
		// insert the keys into the map.
		m.insert(pair<char, number> (c1, n1));
		m.insert(pair<char, number> (c2, n2));
		m.insert(pair<char, number> (c3, n3));
	}
	str.close();
	string result;
	// iterate until the map is empty.
	while (!m.empty()) {
		char beforeChar = '\0';
		// find the "first" element in the map.
		for (map<char, number>::iterator ite = m.begin(); ite != m.end(); ite++) {
			set<char>::size_type size = ite->second.before.size();
			if (size == 0) {
				beforeChar = ite->first;
				break;
			}
		}
		// remove the "to be deleted" association.
		for (map<char, number>::iterator ite = m.begin(); ite != m.end(); ite++) {
			ite->second.before.erase(beforeChar);
		}
		// remove the element.
		m.erase(beforeChar);
		cout << beforeChar;
	}
	cout << endl;
	return 0;
}
