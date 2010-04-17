#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAXNAME 20

static int strcmp2(const void*, const void*);
char **parsenames(FILE *, int);
int countnames(FILE *);
unsigned long long scoreforname(const char*, unsigned long long);

int main(int argc, char **argv) {
	int count = -1;
	unsigned long long score = 0;
	char **arr = NULL;
	FILE *f = fopen("euler22-data", "r");
	if (!f) {
		fprintf(stderr, "err: %s\n", strerror(errno));
		exit(1);
	}
	printf("file descriptor open..\n");
	count = countnames(f);
	printf("countnames() found %d names.\n", count);
	arr = parsenames(f, count);
	printf("names parsed to memory.\n");
	qsort(arr, count, sizeof(void*), strcmp2);
	printf("names sorted..\n");
	{
		unsigned long long i = 0;
		for (i = 0;i < count;i++) {
			unsigned long long tmpscore = scoreforname(arr[i], i + 1);
			score += tmpscore;
		}
	}
	printf("score is: %lld\n", score);
	if (f) {
		fclose(f);
		printf("file descriptor closed..\n");
	}
	return 0;
}

unsigned long long scoreforname(const char *name, unsigned long long number) {
	unsigned long long score = 0;
	while (*name != '\0') {
		score += *name - 'A' + 1;
		name++;
	}
	return score * number;
}

int countnames(FILE *f) {
	int count = 1, input = 0;
	while ((input = fgetc(f)) != EOF)
		if (input == ',')
			count++;
	fseek(f, 0, SEEK_SET);
	return count;
}

char **parsenames(FILE *f, int count) {
	char **arr = calloc(count + 1, sizeof(void*));
	int arrPos = 0;
	int currentPos = 0;
	int inName = 0;
	int input = 0;
	while ((input = fgetc(f)) != EOF) {
		if (input == '\"') {
			if (!inName)
				arr[arrPos] = malloc(MAXNAME);
			inName = inName ? 0 : 1;
		}
		else if (input == ',') {
			arrPos++;
			currentPos = 0;
		}
		else
			arr[arrPos][currentPos++] = (char) input;
	}
	arr[++arrPos] = NULL;
	return arr;
}

static int strcmp2(const void *str1, const void *str2) {
	const char **s1 = (const char **)str1;
	const char **s2 = (const char **)str2;
	return strcmp(*s1, *s2);
}
