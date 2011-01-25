/*
 * euler37.cpp
 *
 *  Created on: 25/01/2011
 *      Author: Dennis Hedegaard
 */

#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

bool prime(int num);

bool truncatable_prime(int num);
bool truncatable_prime_left(const int num);
bool truncatable_prime_right(const int num);

int main() {
	int count = 0;
	int sum = 0;
	for (int i = 11; count < 11; i += 2)
		if (truncatable_prime(i)) {
			sum += i;
			cout << ++count << ": " << i << endl;
		}
	cout << "the sum is: " << sum << endl;
	return 0;
}

bool prime(const int num) {
	if (num < 2)
		return false;
	if (num == 2)
		return true;
	// all even numbers (except 2) aint primes.
	if (num % 2 == 0)
		return false;
	// run until half the number to check, since that's where % 2 starts.
	for (int i = 2; i <= num / 2; i++)
		if (num % i == 0)
			return false;
	return true;
}

bool truncatable_prime(const int num) {
	if (!prime(num))
		return false;
	else if (num < 10)
		return true;
	else
		return truncatable_prime_left(num) && truncatable_prime_right(num);
}

bool truncatable_prime_left(const int num) {
	int left = num / 10; // remove the first left digit
	if (!prime(left))
		return false;
	else if (left < 10)
		return true;
	else
		return truncatable_prime_left(left);
}
bool truncatable_prime_right(const int num) {
	int right = num % (int) pow(10, (int) (log10(num))); // remove the first right digit
	if (!prime(right))
		return false;
	else if (right < 10)
		return true;
	else
		return truncatable_prime_right(right);
}
