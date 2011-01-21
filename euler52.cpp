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

/**
 * Returns true of both sets contain the same values and has the same size.
 */
bool equal_sets(const set<int> set1, const set<int> set2);
bool check(const int num, const int cap);
void print_set(const set<int> set);

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
		set<int> nums;
		int _num = num * i;
		while (_num > 0) {
			int tmp = _num % 10;
			_num /= 10;
			nums.insert(tmp);
		}
		if (!equal_sets(compare_set, nums))
			return false;
	}
	return true;
}

bool equal_sets(const set<int> set1, const set<int> set2) {
	if (set1.size() != set2.size())
		return false;
	set<int>::const_iterator ite1 = set1.begin();
	set<int>::const_iterator ite2 = set2.begin();
	while (ite1 != set1.end()) {
		if (*ite1 != *ite2)
			return false;
		ite1++;
		ite2++;
	}
	return true;
}

void print_set(const set<int> s) {
	cout << "[";
	for (set<int>::const_iterator ite = s.begin(); ite != s.end();) {
		cout << *ite;
		ite++;
		if (ite != s.end())
			cout << ", ";
	}
	cout << "]";
}
