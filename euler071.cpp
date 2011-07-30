#include <iostream>
#include <iomanip>

// #define DEBUG

using namespace std;

#define CAP 1000000

struct _fraction_t {
	unsigned top;
	unsigned bottom;

	_fraction_t(unsigned top, unsigned bottom) {
		this->top = top;
		this->bottom = bottom;
	}

	friend ostream& operator <<(ostream &os, const struct _fraction_t& o);
}typedef fraction_t;

ostream& operator <<(ostream& os, const struct _fraction_t& o) {
	os << o.top << "/" << o.bottom;
	return os;
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

int main(int argc, char **argv) {
	cout << setprecision(20);
	const double upper_bound = 3.0 / 7.0;
	cout << "upper bound: " << upper_bound << endl;
	pair<double, fraction_t> closest_pair(2.0 / 7.0, fraction_t(2, 7));
	bool done = false;
	for (int d = 1; !done;) {
		for (int n = 1; !done;) {
			if (n >= d)
				d++;
			if (d > CAP) {
				done = true;
				break;
			}
			const double val = ((double) n) / d;
			if (val <= closest_pair.first) // if below, push the nominator to make the number bigger
				n++;
			else if (val >= upper_bound) // if above, push denominator to make the number smaller
				d++;
			else if (gcd(n, d) == 1) { // check validity and make the lower bracket.
				closest_pair.first = val;
				closest_pair.second = fraction_t(n, d);
#ifdef DEBUG
				cout << "NEW MAX: " << closest_pair.first << " -- "
						<< closest_pair.second << "\n";
#endif
				n++;
			} else
				throw "fail is fail!";
		}
	}
	cout << "The smallest fraction below " << upper_bound << " where d <= "
			<< CAP << " is " << closest_pair.second << " aka "
			<< closest_pair.first << endl;
	return 0;
}
