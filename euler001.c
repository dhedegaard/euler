#include <stdio.h>

int isvalid(int num);

int main(int argc, char **argv) {
	int i = 0;
	long sum = 0;
	for (i = 0;i < 1000;i++)
		if (isvalid(i))
			sum += i;
	printf("%ld\n", sum);
	return 0;
}

int isvalid(int num) {
	return num % 3 == 0 || num % 5 == 0;
}
