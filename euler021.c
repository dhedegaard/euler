#include <stdio.h>
#include <math.h>

/* http://www.research.att.com/~njas/sequences/A063990 */

int checkamicable(int, int);
int sumdivisors(int);
int test(int n);

int main(int argc, char **argv) {
	int i, sum = 0;
	for (i = 0;i < 8;i++)
		sum += test(i);
	printf("%d\n", checkamicable(20, 34));
	printf("sum: %d\n", sum);
	return 0;
}

int checkamicable(int a, int b) {
	int suma = sumdivisors(a);
	int sumb = sumdivisors(b);
	return suma == b && sumb == a ? 1 : 0;
}

int test(int n) {
	int p = 3 * pow(2, (n - 1)) - 1;
	int q = 3 * pow(2, n) - 1;
	int r = 9 * pow(2, 2 * n - 1) - 1;
	int a = pow(2, n) * p * q;
	int b = pow(2, n) * r;
	printf("%d %d\n", a, b);
	if (checkamicable(a, b) && a < 10000 && b < 10000)
		return a + b;
	else
		return 0;
}

int sumdivisors(int a) {
	int sum = 0;
	int i;
	for (i = 1;i < a;i++)
		if (a % i == 0) {
			sum+=i;
		}
	return sum;
}
