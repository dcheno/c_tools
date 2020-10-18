#include <stdio.h>
#include <assert.h>
#include <sys/time.h>

#include "../src/hash_map.h"

static void test_HashMap() {
	// Just create a new hash map, store a value and make sure you can get it back.
	hash_map* map = HashMap();
	set_key(map, 1, 2);
	int answer = get_key(map, 1);

	assert(2 == answer);
	printf("--- PASSED general_use\n");
}

static void test_keys_with_same_hash() {
	// This is white box testing, but we should make sure that give two keys that will
	// hash the same we can still get their distinct values back.
	hash_map* map = HashMap();
	set_key(map, 1, 10);
	set_key(map, 11, 20);

	assert(10 == get_key(map, 1));
	assert(20 == get_key(map, 11));

	printf("--- PASSED test_keys_with_same_hash\n");
}

static void test_overwrite_same_key() {
	// Setting the same key twice should store the second value.
	hash_map* map = HashMap();
	int hot_key = 21;
	set_key(map, hot_key, 1);
	set_key(map, hot_key, 2);
	assert(2 == get_key(map, hot_key));
	printf("--- PASSED test_overwrite_same_key\n");
}

static void test_range() {
	// More of a performance test than an actual unit test. Check how it performs with a large number
	// of keys.
	int range = 10000000;
	hash_map* map = HashMap();

	struct timeval start;
	gettimeofday(&start, NULL);

	for (int i = 0; i < range; i++) {
		set_key(map, i, i);
	}
	for (int i = 0; i < range; i++) {
		assert(i == get_key(map, i));
	}
	struct timeval stop;
	gettimeofday(&stop, NULL);
	unsigned long elapsed = ((stop.tv_sec * 1000000) + stop.tv_usec) - ((start.tv_sec * 1000000) + start.tv_usec);
	float elapsed_seconds = (float) elapsed/1000000;
	printf("%d sets and gets took %f seconds\n", range, elapsed_seconds);
	printf("--- PASSED test_range\n");
}

int main() {
	test_HashMap();
	test_keys_with_same_hash();
	test_overwrite_same_key();
	test_range();
}
