/*
 * euler59.cpp
 *
 *  Created on: 21/01/2011
 *      Author: Dennis Hedegaard
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>

#define DATA_FILE "euler59-data"

using namespace std;

void read_data(ifstream &stream, vector<char> &v);

int main() {
	cout << "reading data.. " << flush;
	vector<char> data;
	{
		ifstream stream(DATA_FILE, ios_base::in);
		read_data(stream, data);
		stream.close();
	}
	cout << "done, found " << data.size() << " characters." << endl;
	cout << "brute forcing key.. " << flush;
	// setup basic variables for brute force.
	char maxkey1 = 'a', maxkey2 = 'a', maxkey3 = 'a';
	{
		// contains the maximum number of spaces found, for maxkey values.
		int max_spaces = 0;
		// iterate on all possible keys.
		for (char key1 = 'a'; key1 <= 'z'; key1++)
			for (char key2 = 'a'; key2 <= 'z'; key2++)
				for (char key3 = 'a'; key3 <= 'z'; key3++) {
					// defines the key to use.
					int key = 0;
					// contains the number of spaces in this iteration
					int spaces = 0;
					for (vector<char>::size_type i = 0; i < data.size(); i++) {
						// the original value
						char newVal = data[i];
						// XOR to the new value using the given key
						if (key == 0)
							newVal ^= key1;
						else if (key == 1)
							newVal ^= key2;
						else if (key == 2)
							newVal ^= key3;
						// check the value, increase the counter as needed.
						if (newVal == ' ')
							spaces++;
						// go to the next key.
						key = (key + 1) % 3;
					}
					// check to see if we've found a new max number of spaces in this attempt.
					if (spaces > max_spaces) {
						maxkey1 = key1;
						maxkey2 = key2;
						maxkey3 = key3;
						max_spaces = spaces;
					}
				}
		cout << "done, the key has a high chance of being the following \""
				<< maxkey1 << maxkey2 << maxkey3 << "\" with " << max_spaces
				<< " number of spaces found." << endl;
	}
	cout << "decrypting the text again.. " << flush;
	// ends up containing the text decrypted
	vector<char> str;
	{
		int key = 0;
		// iterate on the data, and use the key found on the data.
		for (vector<char>::iterator ite = data.begin(); ite != data.end(); ite++) {
			if (key == 0)
				str.push_back((char) *ite ^ maxkey1);
			else if (key == 1)
				str.push_back((char) *ite ^ maxkey2);
			else if (key == 2)
				str.push_back((char) *ite ^ maxkey3);
			key = (key + 1) % 3;
		}
	}
	// ends up containing the ascii sum.
	int ascii_sum = 0;
	cout << "done" << endl;
	// print the text, if it makes sense it is probably a good choice.
	cout << "\"";
	for (vector<char>::iterator ite = str.begin(); ite != str.end(); ite++) {
		cout << *ite;
		ascii_sum += (int) ((signed char) *ite);
	}
	cout << "\"" << endl;
	cout << "the ascii-sum is: " << ascii_sum << endl;
	return 0;
}

void read_data(ifstream &stream, vector<char> &v) {
	// 1-char buffer to help parse the text.
	char buffer[1];
	// the integer containing parts of a ascii.
	int tmp = 0;
	bool insert = false;
	// read char by char
	while (true) {
		// read to the buffer
		stream.read(buffer, 1);
		// check for EOF
		if (stream.eof())
			break;
		// new number incomming, push the old and clear.
		if (*buffer == ',') {
			v.push_back(tmp);
			tmp = 0;
			insert = false;
		}
		// only parse 'numbers'.
		else if (*buffer >= '0' && *buffer <= '9') {
			if (tmp == 0) {
				tmp = *buffer - '0';
				insert = true;
			} else
				tmp = tmp * 10 + *buffer - '0';
		}
	}
	// we might have a loose end, if we do, push it.
	if (insert)
		v.push_back(tmp);
}
