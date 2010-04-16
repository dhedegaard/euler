#include <stdio.h>
#include <math.h>

/*
 * This implementation works in O(n^2) time, which is a simple brute force,
 * we start at 1, add all the numbers along the way and go back at try to
 * modulus on all the old numbers. This is of course extremely bad for
 * performance as the numbers go higher ^^
 */

/*
 * Counts the number of divisors for a number, including 1 and the number
 * itself, this works in linear time with the number supplied and is bad, when
 * a high number is supplied.
 */
int countdivisors(int);

int main(int argc, char **argv) {
	long long i = 0, triangle = 0, count = -1;
	while (count < 500) {
		count = countdivisors(triangle += ++i);
		if (count > 200)
	 		printf("i: %lld\ttriangle: %lld\tcount: %lld\n", i, triangle, count);
	}
	printf("number: %lld - count: %lld\n", triangle, count);
	return 0;
}

/* For every exact divisor up to the square root, there is a corresponding divisor 
 * above the square root. That means we can do O(sqrt(n) complexity.
 */
int countdivisors(int num) {
	int count, i, sqrtnum;
	if (num < 1)
		return -1;
	count = 0;
	sqrtnum = sqrt(num);
	for (i = 1; i <= sqrtnum; i++)
		if (num % i == 0)
			count+=2;
	if (num == sqrtnum*sqrtnum)
		count--;
	return count;
}
