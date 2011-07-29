#include <iostream>
#include <set>
#include <cstdlib>

using namespace std;

#define DEFAULT_CAP 12000

static unsigned gcd(unsigned, unsigned);

int main(int argc, char **argv) {
	set<double> taken_values;
	double upper_cap = 2.0 / 3.0;
	unsigned cap;
	if (argc != 2)
		cap = DEFAULT_CAP;
	else
		cap = (unsigned) atoi(argv[1]);
	for (unsigned d = 1; d <= cap; d++)
		for (unsigned n = 1; n < d; n++) {
			double val = ((double) n) / d;
			if (val > .5 && val < upper_cap
					&& taken_values.find(val) == taken_values.end()
					&& gcd(n, d) == 1) {
				taken_values.insert(val);
			}
		}
	cout << "total values: " << taken_values.size() << endl;
	return 0;
}

static unsigned gcd(unsigned a, unsigned b) {
	if (a == 0)
		return b;
	while (a != 0)
		if (b > a)
			b -= a;
		else
			a -= b;
	return b;
}
