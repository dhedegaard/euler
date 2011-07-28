// not very optimal sollution.
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

#define CAP 10000

static vector<int> primes;
static vector<int> complements;
static vector<int> odd_composites;

static void generate_primes(int n) {
	assert(n > 1);
	vector<bool> a(true);
	for (int i = 0;i <= n;i++)
		a.push_back(true);
	a.at(0) = false;
	a.at(1) = false;

	for (int i = 2;i * i <= n;i++)
		if (a.at(i))
			for (int j = i * i;j <= n;j += i)
				a.at(j) = false;

	primes.clear();
	complements.clear();
	odd_composites.clear();
	for (int i = 1;i <= n;i++)
		if (a.at(i))
			primes.push_back(i);
		else {
			complements.push_back(i);
			if (i % 2 == 1 && i != 1)
				odd_composites.push_back(i);
		}
}

int main(int argc, char **argv) {
	// generate primes and complements
	cout << "Generating CAP primes.. " << flush;
	generate_primes(CAP);
	cout << "done!" << endl;
	cout << "prime count: " << primes.size() << endl;
	cout << "complement count: " << complements.size() << endl;
	cout << "odd composite count: " << odd_composites.size() << endl;
	// brute force is best force
	for (vector<int>::const_iterator p = primes.begin();p != primes.end();p++)
		for (int i = 1;;i++) {
			int sum = *p + 2 * i * i;
			if (binary_search(odd_composites.begin(), odd_composites.end(), sum)) {
				odd_composites.erase(find(odd_composites.begin(), odd_composites.end(), sum));
				cout << "removed " << sum << "\tnewsize: " << odd_composites.size() << "\tfirst: " << *odd_composites.begin() << "\n";
			}
			else if (sum > CAP)
				break;
		}
	cout << "remaining composites: " << odd_composites.size() << endl;
	cout << "the smallest is: " << *odd_composites.begin() << endl;
	return 0;
}
