#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

struct node {
	int value;
	int sum;
	struct node *parentleft;
	struct node *parentright;
	struct node *left;
	struct node *right;
};

struct node *parse(const char *);
int recursivesum(struct node *);
void freetree(struct node *);

int main(int argc, char **argv) {
	struct node *top = parse("euler18-data");
	if (top != NULL) {
		printf("%d\n", recursivesum(top));
		freetree(top);
	}
	else
		return 1;
	return 0;
}

int recursivesum(struct node *node) {
	if (node->sum == 0) {
		int left = 0, right = 0, sum = node->value;
		if (node->left != NULL)
			left = recursivesum(node->left);
		if (node->right != NULL)
			right = recursivesum(node->right);
		sum += left > right ? left : right;
		node->sum = sum;
		return sum;
	}
	else
		return node->sum;
}

void freetree(struct node *node) {
	if (node->left != NULL)
		freetree(node->left);
	if (node->right != NULL)
		freetree(node->right);
	if (node->parentleft != NULL)
		node->parentleft->right = NULL;
	if (node->parentright != NULL)
		node->parentright->left = NULL;
	free(node);
}

struct node *parse(const char *filename) {
	FILE *f = fopen(filename, "r");
	struct node *top = malloc(sizeof(*top)), *current = top;
	int input = 0, rowcount = 0;
	if (!f) {
		fprintf(stderr, "%s\n", strerror(errno));
		return NULL;
	}
	top->value = 0;
	top->sum = 0;
	top->left = NULL;
	top->right = NULL;
	top->parentright = NULL;
	top->parentleft = NULL;
	while ((input = fgetc(f)) != EOF) {
		if (input == ' ') {
			current = current->parentright;
			if (current->right == NULL) {
				current->right = malloc(sizeof(*current));
				current->right->value = 0;
				current->right->sum = 0;
				current->right->parentleft = current;
				current->right->parentright = NULL;
				current->right->left = NULL;
				current->right->right = NULL;
				if (current->parentright != NULL && current->parentright->right
						!= NULL) {
					current->parentright->right->left = current->right;
					current->right->parentright = current->parentright->right;
				}
			}
			current = current->right;
			rowcount++;
		} else if (input == '\n') {
			int i = 0;
			current = top;
			for (i = 0; i < rowcount + 1; i++) {
				if (current->left == NULL) {
					current->left = malloc(sizeof(*current));
					current->left->value = 0;
					current->left->sum = 0;
					current->left->parentright = current;
					current->left->parentleft = NULL;
					current->left->left = NULL;
					current->left->right = NULL;
					if (current->parentleft != NULL
							&& current->parentleft->left != NULL) {
						current->parentleft->left->right = current->left;
						current->left->parentleft = current->parentleft->left;
					}
				}
				current = current->left;
			}
			rowcount = 0;
		} else if (input >= '0' && input <= '9') {
			if (current->value != 0)
				current->value = current->value * 10 + input - '0';
			else
				current->value = input - '0';
		}
	}
	fclose(f);
	return top;
}

