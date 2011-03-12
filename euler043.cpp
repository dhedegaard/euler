/*
 * euler43.cpp
 *
 *  Created on: 30/01/2011
 *      Author: Dennis Hedegaard
 *
 * Please make sure your compiler supports 64-bit ints (long long).
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

static int sub_vector(vector<int> v, int start, int len);
/* long long is guaranteed to be 64-bits, we need that
 * since 32-bits can't hold all 10-digit numbers. */
static long long vector_to_num(const vector<int> &v);

int main(int argc, char **argv) {
	vector<int> v;
	for (int i = 0; i < 10; i++)
		v.push_back(i);
	sort(v.begin(), v.end());
	long long result = 0;
	while (next_permutation(v.begin(), v.end())) {
		if (v[0] == 0) // skip if first number is 0, since it wont be displayed.
			continue;
		if (v[3] % 2 != 0) // 2-3-4 is / 2, which is index 3 (4th position) to be even.
			continue;
		if (v[5] % 5 != 0)
			continue;
		if (sub_vector(v, 2, 3) % 3 != 0)
			continue;
		if (sub_vector(v, 4, 3) % 7 != 0)
			continue;
		if (sub_vector(v, 5, 3) % 11 != 0)
			continue;
		if (sub_vector(v, 6, 3) % 13 != 0)
			continue;
		if (sub_vector(v, 7, 3) % 17 != 0)
			continue;
		result += vector_to_num(v);
	}
	cout << result << endl;
	return 0;
}

static int sub_vector(vector<int> v, int start, int len) {
	int result = 0;
	for (int i = start; i <= start + len - 1; i++)
		result = result * 10 + v[i];
	return result;
}

static long long vector_to_num(const vector<int> &v) {
	long long result = 0;
	for (vector<int>::const_iterator ite = v.begin(); ite != v.end(); ite++)
		result = result * 10 + *ite;
	return result;
}
