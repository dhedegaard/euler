#include <stdio.h>

int main(int argc, char **argv) {
	long sum = 0;
	int fb = 0, fb1 = 1, fb2 = 0;
	while (fb < 4000000) {
		fb = fb1 + fb2;
		fb2 = fb1;
		fb1 = fb;
		if (fb % 2 == 0)
			sum += fb;
	}
	printf("%ld\n", sum);
	return 0;
}
