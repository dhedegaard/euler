#include <stdio.h>
#include <math.h>
#include <assert.h>

#define NUM 13195
#undef NUM
#define NUM 600851475143

int isprime(long);
void test();

int main(int argc, char **argv) {
	long i = 0, cap = NUM;
	test();
	printf("cap: %ld\n", cap);
	for (i = 2;i < cap;i++)
		if (cap % i == 0 && isprime(cap / i))
			break;
	printf("%ld\n", cap / i);
	return 0;
}

void test() {
	assert(!isprime(4));
	assert(!isprime(6));
	assert(!isprime(8));
	assert(!isprime(10));
	assert(isprime(5));
	assert(isprime(7));
	assert(isprime(13));
	assert(isprime(29));
	assert(!isprime(12));
	assert(!isprime(14));
	assert(!isprime(28));
	assert(!isprime(30));
	assert(isprime(97));
	assert(!isprime(100));
	assert(isprime(101));
	assert(isprime(271));
	assert(!isprime(273));
	printf("tests done..\n");
}

int isprime(long num) {
	printf("check %ld\n", num);
	if (num % 2 == 0)
		return 0;
	else {
		long i = 3;
		while (i * i <= num)
			if (num % i == 0)
				return 0;
			else
				i += 2;
		return 1;
	}
}
