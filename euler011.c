#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <errno.h>
#include <string.h>

int main(int argc, char **argv) {
	int arr[20][20], x = 0, y = 0, sum = 0;
	printf("initialize array..\n");
	for (y = 0;y < 20;y++)
		for (x = 0;x < 20;x++)
			arr[y][x] = 0;
	printf("opening file pointer..\n");
	FILE *f = fopen("euler11-data", "r");
	if (!f) {
		fprintf(stderr, "error opening file pointer: %s\n", strerror(errno));
		exit(1);
	}
	printf("parsing file -> array..\n  ");
	for (y = 0;y < 20;y++) {
		for (x = 0;x < 20;x++) {
			char a = 0, b = 0;
			int result = 0;
			while (!isdigit(a))
				fscanf(f, "%c", &a);
			while (!isdigit(b))
				fscanf(f, "%c", &b);
			arr[y][x] = result = (a - '0') * 10 + (b - '0');
			printf("%2d ", result);
		}
		printf("\n");
		if (y < 19)
			printf("  ");
	}
	printf("done parsing array..\n");
	fclose(f);
	printf("closing file pointer..\n");
	printf("running horizontally..\n");
	for (y = 0;y < 20;y++)
		for (x = 0;x < 16;x++) {
			int newsum = arr[y][x] *
				arr[y][x + 1] *
				arr[y][x + 2] *
				arr[y][x + 3];
			if (newsum > sum)
				sum = newsum;
		}
	printf("sum is now: %d\n", sum);
	printf("running vertically..\n");
	for (y = 0;y < 16;y++)
		for (x = 0;x < 20;x++) {
			int newsum = arr[y][x] *
				arr[y + 1][x] *
				arr[y + 2][x] *
				arr[y + 3][x];
			if (newsum > sum)
				sum = newsum;
		}
	printf("sum is now: %d\n", sum);
	printf("running forward vertical..\n");
	for (y = 3;y < 20;y++)
		for (x = 0;x < 16;x++) {
			int newsum = arr[y][x] *
				arr[y - 1][x + 1] *
				arr[y - 2][x + 2] *
				arr[y - 3][x + 3];
			if (newsum > sum)
				sum = newsum;
		}
	printf("sum is now: %d\n", sum);
	printf("running backward vertical..\n");
	for (y = 0;y < 16;y++)
		for (x = 3;x < 20;x++) {
			int newsum = arr[y][x] *
				arr[y + 1][x - 1] *
				arr[y + 2][x - 2] *
				arr[y + 3][x - 3];
			if (newsum > sum)
				sum = newsum;
		}
	printf("sum is now: %d\n", sum);
	return 0;
}
