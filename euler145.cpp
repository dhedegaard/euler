/*
 * euler145.cpp
 *
 *  Created on: 01/03/2011
 *      Author: Dennis Hedegaard
 */

#include <iostream>
#include <pthread.h>
#include <vector>

using namespace std;

#define DEBUG 0

static volatile int count = 0;
// mutex for modifying the count variable.
static pthread_mutex_t count_mutex = PTHREAD_MUTEX_INITIALIZER;
// mutex for modifying the cout stream.
static pthread_mutex_t cout_mutex = PTHREAD_MUTEX_INITIALIZER;

#define CAP 1000000000

static long long reverse(long long n);
static bool consists_odd(long long n);
static bool is_reversible(long long i);
static void *work(void *args) {
	// parse the arguments from the pointer
	int *limits;
	limits = (int*) args;
	// iterate
	for (int i = limits[0]; i < limits[1]; i++) {
		if (is_reversible(i)) {
			pthread_mutex_lock(&count_mutex);
			count++;
			pthread_mutex_unlock(&count_mutex);
		}
	}
	// announce and let the thread return
	pthread_mutex_lock(&cout_mutex);
	cout << limits[0] << " -> " << limits[1] << endl;
	pthread_mutex_unlock(&cout_mutex);
}

int main(int argc, char **argv) {
	pthread_t threads[4];
	int params[][2] = { { 0, 250000000 }, { 250000001, 500000000 }, {
			500000001, 750000000 }, { 750000001, 1000000000 } };
	pthread_create(&threads[0], NULL, work, (void*) &params[0]);
	pthread_create(&threads[1], NULL, work, (void*) &params[1]);
	pthread_create(&threads[2], NULL, work, (void*) &params[2]);
	pthread_create(&threads[3], NULL, work, (void*) &params[3]);
	pthread_join(threads[0], NULL);
	pthread_join(threads[1], NULL);
	pthread_join(threads[2], NULL);
	pthread_join(threads[3], NULL);
	cout << count << endl;
	return 0;
}

static bool is_reversible(long long i) {
	if (i % 10 == 0) // skip leader zeros
		return false;
	long long rev = reverse(i);
	if (rev == -1) // skip leading zeros in reverse
		return false;
	long long sum = i + rev;
	// check for odd decimal sum
	if (consists_odd(sum)) {
		if (DEBUG)
			cout << i << " + " << rev << " = " << sum << endl;
		return true;
	} else
		return false;
}

static bool consists_odd(long long n) {
	while (n > 0) {
		if ((n % 10) % 2 == 0)
			return false;
		n /= 10;
	}
	return true;
}

static long long reverse(long long n) {
	// avoid leading zeros.
	if (n % 10 == 0)
		return -1;
	long long result = 0;
	// iterate and return
	while (n > 0) {
		result = result * 10 + (n % 10);
		n /= 10;
	}
	return result;
}
