#include <stdlib.h>
#include "key_value.h"

key_value_pair* KeyValuePair(int key, int value) {
	key_value_pair* pair = malloc(sizeof(key_value_pair));
	pair->key = key;
	pair->value = value;
	return pair;
}
