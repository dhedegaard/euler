/* This code is based upon max for each 10'th tier is divisible
 * by 6. So let the algorithm run for enough time to find it or solve
 * it by simple math based on the using the formula for the euler
 * algorithm. */
#include <iostream>
#include <cassert>

using namespace std;

static unsigned gcd(unsigned m, unsigned n);
static unsigned phi(unsigned i);

int main(int argc, char **argv) {
	assert(phi(2) == 1);
	assert(phi(3) == 2);
	assert(phi(4) == 2);
	assert(phi(5) == 4);
	assert(phi(6) == 2);
	assert(phi(7) == 6);
	assert(phi(8) == 4);
	assert(phi(9) == 6);
	assert(phi(10) == 4);
	int max_i = 2;
	double max_n_phi = 1;
	for (unsigned i = 6; i <= 1000000; i+=6) {
		double d = i / (double) phi(i);
		if (max_n_phi < d) {
			max_n_phi = d;
			max_i = i;
			cout << i << ": " << d << endl;
		}
	}
	cout << "max: " << max_i << " -> " << max_n_phi << endl;
	return 0;
}

static unsigned phi(unsigned i) {
	unsigned result = 0;
	for (unsigned _i = 1;_i < i;_i++)
		if (gcd(i, _i) == 1)
			result++;
	return result;
}

static unsigned gcd(unsigned register m, unsigned register n) {
	if (m == 0)
		return n;
	while (n != 0)
		if (m > n)
			m -= n;
		else
			n -= m;
	return m;
}
