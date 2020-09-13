/*
 * key_value.c
 *
 *  Created on: Sep 12, 2020
 *      Author: dan
 */
#include <stdlib.h>
#include "key_value.h"

/* Returns a pointer to a key value pair with the given key and value */
key_value_pair* KeyValuePair(int key, int value) {
  /*key_value_pair pair;
  pair.key = key;
  pair.value = value;
  return pair;*/
	key_value_pair* pair = malloc(sizeof(key_value_pair));
	pair->key = key;
	pair->value = value;
	return pair;
}
