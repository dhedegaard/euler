/*
 * euler52.cpp
 *
 *  Created on: 19/01/2011
 *      Author: Dennis Hedegaard
 */

#include <iostream>
#include <set>

// The number of multiplies to check
#define X 6

using namespace std;

bool check(const int num, const int cap);

int main() {
	for (int i = 1; true; i++)
		if (check(i, X)) {
			cout << "found:\t";
			for (int j = 1; j <= X; j++) {
				cout << i * j;
				if (j < X)
					cout << " == ";
			}
			cout << endl;
			break;
		}
	return 0;
}

bool check(int num, const int cap) {
	set<int> compare_set;
	{
		int _num = num;
		while (_num > 0) {
			int tmp = _num % 10;
			_num /= 10;
			compare_set.insert(tmp);
		}
	}
	for (int i = 2; i <= cap; i++) {
		int _num = num * i;
		while (_num > 0) {
			int tmp = _num % 10;
			_num /= 10;
			if (compare_set.find(tmp) == compare_set.end())
				return false;
		}
	}
	return true;
}
