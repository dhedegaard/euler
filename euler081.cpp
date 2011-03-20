/*
 * euler081.cpp
 *
 *  Created on: 19/03/2011
 *      Author: Dennis Hedegaard
 */

#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <cassert>
#include <climits>

#define DATA_FILE "euler081-data"

using namespace std;

struct _node_t {
	int value;
	int min_sum; // holds the minimum sum to this point.
	bool end;
	_node_t *below, *right;
}typedef node_t;

/**
 * Returns a note_t** that's null terminated in both "directions".
 */
static node_t** parse();
static int get_min_sum(node_t* node);

int main(int argc, char **argv) {
	node_t** grid = parse();
	cout << get_min_sum(&grid[0][0]) << endl;
	return 0;
}

static int get_min_sum(node_t* node) {
	if (node->min_sum < INT_MAX)
		return node->min_sum;
	int below = INT_MAX;
	if (node->below != NULL && !node->below->end)
		below = get_min_sum(node->below);
	int right = INT_MAX;
	if (node->right != NULL && !node->right->end)
		right = get_min_sum(node->right);
	int sum = node->value;
	if (below != INT_MAX && right != INT_MAX)
		sum += below < right ? below : right;
	else if (below != INT_MAX && right == INT_MAX)
		sum += below;
	else if (below == INT_MAX && right != INT_MAX)
		sum += right;
	node->min_sum = sum;
	return sum;
}

static node_t** parse() {
	ifstream in(DATA_FILE);
	char buffer[8095];
	streamsize read = -1;
	vector<char> tmp;
	// read from the stream into the vector buffer.
	{
		while ((read = in.readsome(buffer, 8094)) > 0) {
			for (int i = 0; i < read; i++)
				tmp.push_back(buffer[i]);
		}
	}
	in.close();
	// allocate results and set terminators.
	node_t** result = (node_t**) calloc(sizeof(*result), 81);
	{
		for (int y = 0; y < 81; y++) {
			result[y] = (node_t*) calloc(sizeof(*result[y]), 81);
			for (int x = 0; x < 80; x++) {
				// set the sum high, so we can only underbid the first time.
				result[y][x].min_sum = INT_MAX;
				// set the right pointer.
				if (x > 0)
					result[y][x - 1].right = &result[y][x];
				// set the below pointer.
				if (y > 0)
					result[y - 1][x].below = &result[y][x];
			}
			// set the end bit on the last element in each "row".
			result[y][80].end = true;
		}
		// set the end bit on the last "row".
		for (int x = 0;x < 80;x++)
			result[80][x].end = true;
	}
	// parse from the tmp vector.
	{
		int i = 0;
		int x = 0;
		int y = 0;
		for (vector<char>::iterator ite = tmp.begin(); ite != tmp.end(); ite++) {
			if (isdigit(*ite)) { // append to i and proceed.
				i = i * 10 + (int) (*ite - '0');
			} else if (*ite == ',') { // comma means new number in same row.
				result[y][x++].value = i;
				i = 0;
			} else if (*ite == '\n') { // new line, means new "row".
				assert(x == 79);
				result[y][x++].value = i;
				assert(x == 80);
				assert(result[y][x].end);
				y++;
				x = 0;
				i = 0;
			}
		}
	}
	return result;
}
