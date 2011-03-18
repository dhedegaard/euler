/*
 * euler63.cpp
 *
 *  Created on: 29/01/2011
 *      Author: Dennis Hedegaard
 */

#include <iostream>
#include <gmpxx.h>

using namespace std;

static int pow_digit_count(int num, int exp);

int main() {
	int count = 0;
	for (int exp = 1; exp <= 51; exp++)
		for (int num = 1; num <= 10; num++) {
			int digits = pow_digit_count(num, exp);
			if (digits == exp)
				count++;
			else if (digits > exp)
				break;
		}
	cout << count << endl;
	return 0;
}

static int pow_digit_count(int num, int exp) {
	mpz_class result = 1;
	while (exp-- > 0)
		result *= num;
	return result.get_str(10).size();
}
