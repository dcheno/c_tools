#include<stdio.h>
#include<assert.h>
#include "../src/key_value.h"

int main() {
	// Pretty straightforward, just makes sure you can store a key and a value.
	int key = 1;
	int value = 2;
	key_value_pair* pair = KeyValuePair(1,2);
	assert(key == pair->key);
	assert(value == pair->value);
	printf("--- PASSED make a key value pair ---\n");
}
