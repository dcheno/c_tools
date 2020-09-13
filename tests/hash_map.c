#include <stdio.h>
#include <assert.h>

#include "../src/hash_map.h"

static void test_HashMap() {

	hash_map* map = HashMap();
	set_key(map, 1, 2);
	int answer = get_key(map, 1);

	assert(2 == answer);
	printf("--- PASSED test_HashMap ---\n");
}

static void test_KeysWithSameHash() {

}

int main() {
	test_HashMap();
}
