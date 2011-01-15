/*
 * euler42.cpp
 *
 *  Created on: 15/01/2011
 *      Author: neo2k
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <set>

using namespace std;

static void read_and_parse(ifstream &input, set<string> &data);

static int longest_word(const set<string> &data);

static void
generate_triangle_numbers(const int max, set<int> &triangle_numbers);

static bool is_triangle_word(const string word,
		const set<int> &triangle_numbers);

int main() {
	set<string> data;
	ifstream f("euler42-data");
	if (!f.good()) { // check to see if we can read from the data.
		cerr << "error: unable to read data." << endl;
		return 1;
	}
	cout << "reading and parsing.. " << flush;
	read_and_parse(f, data);
	f.close();
	cout << "found " << data.size() << " words." << endl;
	cout << "finding longest word.. " << flush;
	string::size_type size = longest_word(data);
	cout << "longest word is " << size << " characters." << endl;
	int max_triangle = size * 30;
	cout << "largest possible triangle number cannot exceed " << max_triangle
			<< endl;
	cout << "generating triangle number set.. " << flush;
	set<int> triangle_numbers;
	generate_triangle_numbers(max_triangle, triangle_numbers);
	cout << "done, generated " << triangle_numbers.size() << " numbers."
			<< endl;
	cout << "finding triangle words in the word list.. " << flush;
	int count = 0;
	for (set<string>::iterator ite = data.begin(); ite != data.end(); ite++)
		if (is_triangle_word(*ite, triangle_numbers))
			count++;
	cout << "found " << count << " triangle words." << endl;
	return 0;
}

static void read_and_parse(ifstream &input, set<string> &data) {
	string buffer, tmp_data;
	while (input >> tmp_data)
		buffer += tmp_data;
	bool in_word = false;
	string new_word;
	for (string::iterator ite = buffer.begin(); ite != buffer.end(); ite++) {
		if (*ite == '"') {
			if (in_word)
				data.insert(new_word);
			else
				new_word = "";
			in_word = !in_word;
		} else if (*ite != ',')
			new_word += *ite;
	}
}

static int longest_word(const set<string> &data) {
	string::size_type size = 0;
	for (set<string>::const_iterator ite = data.begin(); ite != data.end(); ite++)
		if (ite->size() > size)
			size = ite->size();
	return size;
}

static void generate_triangle_numbers(const int max, set<int> &triangle_numbers) {
	int i = 1;
	while (true) {
		int t = .5 * i * (i + 1);
		if (t > max)
			return;
		triangle_numbers.insert(t);
		i++;
	}
}

static bool is_triangle_word(const string word,
		const set<int> &triangle_numbers) {
	int value = 0;
	for (string::const_iterator ite = word.begin(); ite != word.end(); ite++)
		value += *ite - 'A' + 1;
	if (triangle_numbers.find(value) != triangle_numbers.end())
		return true;
	return false;
}
