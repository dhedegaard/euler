#include <stdio.h>

#define WIDTH 21
#define HEIGHT 21

long long cache[HEIGHT + 1][WIDTH + 1];
long long count = 0;

long long countways(int x, int y);

int main(int argc, char **argv) {
	int x, y;
	for (y = 0;y < HEIGHT;y++)
		for (x = 0;x < WIDTH;x++)
			cache[y][x] = -1;
	cache[WIDTH - 1][HEIGHT - 1] = 1;
	count = countways(0, 0);
	printf("count: %lld\n", count);
	return 0;
}

long long countways(int x, int y) {
	long long ways = 0;
	if (cache[y][x] != -1)
		return cache[y][x];
	else {
		if (x < WIDTH)
			ways += countways(x + 1, y);
		if (y < HEIGHT)
			ways += countways(x, y + 1);
	}
	cache[y][x] = ways;
	printf("x %d y %d - %lld\n", x, y, ways);
	return ways;
}
