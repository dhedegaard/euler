#include <iostream>
#include <cassert>
#include <map>

using namespace std;

#define CAP 10000000

static map<int, int> cache;

static int square_digits(int i) {
	int result = 0;
	while (i > 0) {
		int tmp = i % 10;
		result += tmp * tmp;
		i /= 10;
	}
	return result;
}

int main(int argc, char **argv) {
	cout << "running tests.. " << flush;
	assert(square_digits(44) == 32);
	assert(square_digits(85) == 89);
	assert(square_digits(89) == 145);
	assert(square_digits(145) == 42);
	assert(square_digits(42) == 20);
	assert(square_digits(20) == 4);
	assert(square_digits(4) == 16);
	assert(square_digits(16) == 37);
	assert(square_digits(37) == 58);
	assert(square_digits(58) == 89);
	cout << "done" << endl;
	int low = 0;
	int high = 0;
	cout << "calculating number chains for all number up to " << CAP << ".." << endl;
	for (int i = 1;i < CAP;i++) {
		int tmp = i;
		while (true) {
			tmp = square_digits(tmp);
			map<int, int>::const_iterator ite = cache.find(tmp);
			if (ite != cache.end()) {
				if (ite->second == 1)
					low++;
				else if (ite->second == 89)
					high++;
				// somehow it makes performance worse, maybe because of rehashing or balancing a rbtree ?
				// cache.insert(pair<int, int>(i, ite->second));
				break;
			}
			if (tmp == 1) {
				low++;
				cache.insert(pair<int, int>(i, 1));
				break;
			}
			else if (tmp == 89) {
				high++;
				cache.insert(pair<int, int>(i, tmp));
				break;
			}
		}
	}
	cout << endl << "1: " << low << endl;
	cout << "89: " << high << endl;
	return 0;
}
